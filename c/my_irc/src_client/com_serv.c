#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <gtk/gtk.h>
#include "client/gtk.h"
#include "client/client.h"
#include "client/cmd_client.h"
#include "client/gere_cmd.h"
#include "client/utils.h"
#include "client/str_to_wordtab.h"
#include "client/x.h"

int	send_serv(t_main_win *m, char *msg, int fd)
{
  char	*tmp;
  int	res;

  tmp = Xmalloc(strlen(msg) + 3);
  strcpy(tmp, msg);
  strcat(tmp, "\n\r");
  if ((res = send(fd, tmp, strlen(tmp), 0)) == -1)
    {
      free(tmp);
      tmp = Xmalloc(strlen(msg) + 30);
      sprintf(tmp, "Error while sending %s to %d\n", msg, fd);
      aff_msg(m, tmp);
    }
  free(tmp);
  return (res);
}

static int	in_buf(t_main *c, char ch)
{
  if (((c->end + 1) % BUF_SIZE) != c->start)
    {
      (c->buf)[c->end] = ch;
      c->end = (c->end + 1) % BUF_SIZE;
      return (1);
    }
  (c->buf)[BUF_SIZE - 1] = '\n';
  return (0);
}

static int	out_buf(t_main *c, int start, int end)
{
  char		buf[BUF_SIZE];
  int		i;

  i = 0;
  while (start != end)
    {
      buf[i++] = (c->buf)[start];
      start = (start + 1) % BUF_SIZE;
    }
  strcpy(c->buf, buf);
  (c->buf)[i] = '\0';
  return (1);
}

static int	add_buffer(t_main *c, char *buf, int len)
{
  int		i;
  int		start;
  int		end;

  i = 0;
  while (i != len)
    if (!in_buf(c, buf[i++]))
      break;
  start = c->start;
  end = c->end;
  while (start != end)
    {
      if (c->buf[start] == '\n')
	return (out_buf(c, 0, start));
      start = (start + 1) % BUF_SIZE;
    }
  c->start = start;
  return (0);
}

void	recv_serv(t_main *c)
{
  char	buf[BUF_SIZE + 1];
  int	len;

  memset(buf, 0, BUF_SIZE + 1);
  if ((len = recv(c->sfd, buf, BUF_SIZE, 0)) <= 0)
    disconnect(c);
  if (!add_buffer(c, buf, len))
    return ;
  c->start = 0;
  c->end = 0;
  str_clean(c->buf, strlen(c->buf));
  aff_msg(c->m, str_clean(c->buf, strlen(c->buf)));
  memset(c->buf, 0, BUF_SIZE + 3);
}
