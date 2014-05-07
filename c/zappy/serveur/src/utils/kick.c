#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "colors.h"
#include "actions_graph/actions_graph.h"
#include "transfer/send.h"
#include "utils/ban.h"
#include "utils/kick.h"
#include "utils/list_buf.h"
#include "utils/x.h"

static void	kick_close(t_stck *s, int fd)
{
  char		*tmp;

  _X((void *)-1, (void *)shutdown(fd, SHUT_RD), "shutdown");
  if (_X((void *)-1, (void *)close(fd), "close") != (void *)-1)
    {
      if (s->fds[fd].type == FD_IA)
	{
	  send_graphic((tmp = get_oneint("pdi", fd)), s);
	  free(tmp);
	}
      printf(REDG"\nClient #%d gone away%s\n\n", fd, DEFAULT);
      if (s->fds[fd].err >= MAX_ERR)
	ban(&(s->ban), s->fds[fd].ip, fd);
    }
}

int	kick(t_stck *s, int fd, char *msg)
{
  if (msg)
    {
      if (!strlen(msg))
	send_one("mort", fd, s);
      else
	send_one(msg, fd, s);
    }
  kick_close(s, fd);
  if (s->fds[fd].cbuf_read.begin)
    free_buffer(&(s->fds[fd].cbuf_read.begin));
  if (s->fds[fd].cbuf_write.begin)
    free_buffer(&(s->fds[fd].cbuf_write.begin));
  if (s->fds[fd].ip)
    free(s->fds[fd].ip);
  memset(&(s->fds[fd]), 0, sizeof(t_fd));
  return (0);
}
