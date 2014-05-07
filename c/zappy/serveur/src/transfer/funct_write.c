#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "transfer/send.h"
#include "transfer/funct_write.h"
#include "utils/cbuf.h"
#include "utils/kick.h"
#include "utils/x.h"

int	funct_write(t_stck *s, int fd)
{
  char	*buf;
  int	res;

  if (!(buf = get_buffer(&(s->fds[fd].cbuf_write), s, fd, 0)))
    return (0);
  if (recv(fd, NULL, 0, 0) < 0)
    {
      free(buf);
      kick(s, fd, NULL);
      return (0);
    }
  res = send_split(buf, fd);
  free(buf);
  return (res);
}

int	funct_dead(t_stck *s, int fd)
{
  send_one("mort", fd, s);
  s->fds[fd].fct_write = funct_kick;
  return (0);
}

int	funct_kick(t_stck *s, int fd)
{
  funct_write(s, fd);
  kick(s, fd, NULL);
  return (0);
}

int	send_now(char *msg, t_stck *s, int fd)
{
  char	*mode;
  char	*tmp;
  int	res;

  mode = "\n";
  if (s->fds[fd].tmode)
    mode = s->fds[fd].tmode;
  tmp = Xmalloc(strlen(msg) + strlen(mode) + 1);
  sprintf(tmp, "%s%s", msg, mode);
  res = (int)_X((void *)-1, (void *)send(fd, tmp, strlen(tmp), 0), "send");
  free(tmp);
  return (0);
}
