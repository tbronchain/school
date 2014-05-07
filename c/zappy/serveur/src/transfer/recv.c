#include <math.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "colors.h"
#include "transfer/send.h"
#include "transfer/recv.h"
#include "utils/free.h"
#include "utils/lib.h"
#include "utils/cbuf.h"
#include "utils/list_buf.h"
#include "utils/kick.h"
#include "utils/x.h"

void	recv_client(t_stck *s, int fd)
{
  char	*tmp;
  char	buf[BUF_SIZE + 1];
  int	len;

  memset(buf, 0, BUF_SIZE + 1);
  if ((len = recv(fd, buf, BUF_SIZE, 0)) <= 0)
    {
      kick(s, fd, NULL);
      return ;
    }
  printf("Receiving from %s%d%s:\t%s%s%s\n",
	 BLUEG, fd, DEFAULT, YELLOWG, str_clean((tmp = strdup(buf))), DEFAULT);
  free(tmp);
  add_buffer(&(s->fds[fd].cbuf_read), s, buf, len);
  while (test_buffer(&(s->fds[fd].cbuf_read)))
    {
      s->fds[fd].buf_read = get_buffer(&(s->fds[fd].cbuf_read), s, fd, 1);
      s->fds[fd].fct_read(s, fd, s->fds[fd].buf_read);
      s->fds[fd].buf_read = xfree(s->fds[fd].buf_read);
    }
}
