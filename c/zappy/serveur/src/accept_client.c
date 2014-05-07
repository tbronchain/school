#include <sys/types.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "colors.h"
#include "accept_client.h"
#include "utils/x.h"
#include "transfer/send.h"
#include "utils/kick.h"
#include "utils/ban.h"
#include "actions_graph/init_graphic.h"
#include "actions_ia/check_action_ia.h"
#include "actions_graph/check_action_graph.h"
#include "actions_ia/init_ia.h"
#include "transfer/funct_write.h"

int	select_client(t_stck *s, int fd, char *buf)
{
  int	res;

  if (!strcmp(buf, "GRAPHIC"))
    {
      s->fds[fd].type = FD_GRAPH;
      init_graphic(s, fd);
      s->fds[fd].fct_read = check_action_graph;
    }
  else
    {
      s->fds[fd].type = FD_IA;
      s->fds[fd].fct_read = check_action_ia;
      if ((res = init_ia(s, fd, buf)) == -1)
	{
	  send_one("ko", fd, s);
	  s->fds[fd].fct_write = funct_kick;
	}
      else if (res == -2)
	{
	  send_now("ko", s, fd);
	  kick(s, fd, NULL);
	}
    }
  return (0);
}

void	init_client(t_stck *s, int cfd, int id)
{
  memset(&(s->fds[cfd]), 0, sizeof(t_fd));
  s->fds[cfd].id = id;
  s->fds[cfd].type = FD_CLIENT;
  s->fds[cfd].fct_read = select_client;
  s->fds[cfd].fct_write = funct_write;
  s->fds[cfd].cbuf_read.max = BUF_MAX;
  s->fds[cfd].cbuf_write.max = 0;
}

int			accept_client(t_stck *s, int fd)
{
  static int		id = 0;
  struct sockaddr_in	csin;
  unsigned int		csin_len;
  int			cfd;

  csin_len = 0;
  memset(&csin, 0, sizeof(csin));
  cfd = (int)_X((void *)-1, (void *)accept(fd, (struct sockaddr *)&csin,
					   &csin_len), "accept");
  if (cfd <= 0)
    return (0);
  else if (check_ban(&(s->ban), (char *)(&csin.sin_addr), cfd))
    return (0);
  printf(REDG"\nNew client #%d from %s:%d%s\n\n", cfd,
	 inet_ntoa(csin.sin_addr), ntohs(csin.sin_port), DEFAULT);
  init_client(s, cfd, id);
  s->fds[cfd].ip = Xmalloc(sizeof(struct in_addr) + 1);
  memcpy(s->fds[cfd].ip, (char *)(&csin.sin_addr), sizeof(struct in_addr));
  send_one("BIENVENUE", cfd, s);
  id = (id + 1) % ID_MAX_SIZE;
  return (0);
}
