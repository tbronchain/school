#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur/serveur.h"
#include "serveur/cmd_serv.h"
#include "serveur/init.h"
#include "serveur/client_read.h"
#include "serveur/lib.h"
#include "serveur/channel.h"
#include "serveur/send.h"
#include "serveur/list.h"
#include "serveur/x.h"

t_cmd	gl_cmd[] =
  {
    {"/nick", nick},
    {"/list", list},
    {"/join", join},
    {"/part", part},
    {"/users", users},
    {"/msg", msg},
    {"/quit", quit},
    {"/me", me},
    {0, 0}
  };

static int	check_cmd(t_stck *s, int fd)
{
  char		**cmd;
  int		i;

  i = 0;
  cmd = str_to_wordtab(str_clean(s->fds[fd].buf_read));
  if (!null(cmd[0]))
    return (-1);
  while (gl_cmd[i].cmd)
    {
      if (!strcmp(cmd[0], gl_cmd[i].cmd))
	return (gl_cmd[i].funct(s, fd, cmd));
      i++;
    }
  return (0);
}

static int	in_buf(t_stck *s, char c, int fd)
{
  if (((s->fds[fd].end + 1) % BUF_SIZE) != s->fds[fd].start)
    {
      (s->fds[fd].buf_read)[s->fds[fd].end] = c;
      s->fds[fd].end = (s->fds[fd].end + 1) % BUF_SIZE;
      return (1);
    }
  (s->fds[fd].buf_read)[BUF_SIZE] = '\n';
  (s->fds[fd].buf_read)[BUF_SIZE + 1] = '\r';
  return (0);
}

static int	out_buf(t_stck *s, int fd, int start, int end)
{
  char		buf[BUF_SIZE];
  int		i;

  i = 0;
  while (start != end)
    {
      buf[i++] = (s->fds[fd].buf_read)[start];
      start = (start + 1) % BUF_SIZE;
    }
  strcpy(s->fds[fd].buf_read, buf);
  s->fds[fd].buf_read[i] = '\0';
  return (1);
}

static int	add_buffer(t_stck *s, int fd, char *buf, int len)
{
  int		i;
  int		start;
  int		end;

  i = 0;
  while (i != len)
    if (!in_buf(s, buf[i++], fd))
      break;
  start = s->fds[fd].start;
  end = s->fds[fd].end;
  while (start != end)
    {
      if ((s->fds[fd].buf_read)[start] == '\n')
	return (out_buf(s, fd, 0, start));
      start = (start + 1) % BUF_SIZE;
    }
  s->fds[fd].start = start;
  return (0);
}

void	client_read(t_stck *s, int fd)
{
  char	*tmp;
  char	buf[BUF_SIZE + 1];
  int	len;

  memset(buf, 0, BUF_SIZE + 1);
  if ((len = recv(fd, buf, BUF_SIZE, 0)) <= 0)
    {
      _X((void *)-1, (void *)close(fd), "close");
      if (s->fds[fd].channel[0])
	{
	  tmp = my_strcat(s->fds[fd].nickname, " has left the channel.");
	  send_oth(s, fd, tmp, s->fds[fd].channel, SERVER_NAME);
	  free(tmp);
	}
      memset(&(s->fds[fd]), 0, sizeof(t_fd));
      printf("client #%d gone away\n", fd);
      return ;
    }
  if (!add_buffer(s, fd, buf, len))
    return ;
  s->fds[fd].start = 0;
  s->fds[fd].end = 0;
  if (!check_cmd(s, fd))
    send_all(s, s->fds[fd].buf_read, s->fds[fd].channel, s->fds[fd].nickname);
  memset(s->fds[fd].buf_read, 0, BUF_SIZE + 3);
}
