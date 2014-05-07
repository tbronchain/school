#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "colors.h"
#include "transfer/send.h"
#include "utils/cbuf.h"
#include "utils/kick.h"
#include "utils/lib.h"
#include "utils/x.h"

int	send_one(char *msg, int fd, t_stck *s)
{
  char	*mode;
  char	*tmp;

  mode = "\n";
  if (s->fds[fd].tmode)
    mode = s->fds[fd].tmode;
  tmp = Xmalloc(strlen(msg) + strlen(mode) + 3);
  sprintf(tmp, "%s%s", msg, mode);
  add_buffer(&(s->fds[fd].cbuf_write), s, tmp, strlen(tmp));
  free(tmp);
  return (0);
}

int	send_graphic(char *msg, t_stck *s)
{
  int	i;

  i = 0;
  while (i < s->lim_fd)
    {
      if (s->fds[i].type == FD_GRAPH)
	send_one(msg, i, s);
      i++;
    }
  return (strlen(msg));
}

int	send_all(t_stck *s, char *msg, int type1, int type2)
{
  int	res;
  int	i;

  i = 0;
  res = 0;
  if (!msg)
    return (0);
  else if (!strlen(msg))
    return (0);
  while (i < s->lim_fd)
    {
      if ((s->fds[i]).type == type1 || (s->fds[i]).type == type2)
	if (send_one(msg, i, s) > 0)
	  res++;
      i++;
    }
  return (res);
}

int	send_split(char *buf, int fd)
{
  char	*s;
  char	*tmp;
  char	*max;
  int	res;

  res = 0;
  tmp = buf;
  max = buf + strlen(buf);
  s = str_clean(strdup(buf));
  printf("Sending to %s%d%s:\t\t%s%s%s\n",
	 BLUEG, fd, DEFAULT, GREENG, s, DEFAULT);
  while (tmp < max)
    {
      res = (int)(max - tmp) > BUF_SIZE ? BUF_SIZE
	: (int)(max - tmp) % BUF_SIZE;
      if ((res = send(fd, buf, strlen(buf), 0)) <= 0)
	{
	  fprintf(stderr, "Error while sending %s to %d\n", s, fd);
	  break;
	}
      tmp += BUF_SIZE;
    }
  free(s);
  return (res);
}

int	send_ko(t_stck *s, int fd)
{
  return (send_one("ko", fd, s));
}
