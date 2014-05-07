#include <sys/resource.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur/serveur.h"
#include "serveur/init.h"
#include "serveur/client_read.h"
#include "serveur/x.h"

void			accept_client(t_stck *s, int fd)
{
  struct sockaddr_in	csin;
  unsigned int		csin_len;
  int			cfd;
  char			*user;

  cfd = (int)X((void *)-1, (void *)accept(fd, (struct sockaddr *)&csin,
					  &csin_len), "accept");
  printf("New client #%d from %s:%d\n", cfd,
	 inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
  memset(&(s->fds[cfd]), 0, sizeof(t_fd));
  if (!(user = getenv("USER")))
    user = "user";
  strcpy((s->fds[cfd].nickname), user);
  (s->fds[cfd]).type = FD_CLIENT;
  (s->fds[cfd]).fct_read = client_read;
}

void			launch_serv(t_stck *s)
{
  struct protoent	*p;
  struct sockaddr_in	sin;
  int			fd;

  p = (struct protoent *)X(NULL, getprotobyname("tcp"), "getprotobyname");
  fd = (int)X((void *)-1, (void *)socket(PF_INET, SOCK_STREAM, p->p_proto),
	      "socket");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(s->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  X((void *)-1, (void *)bind(fd, (struct sockaddr *)&sin, sizeof(sin)), "bind");
  X((void *)-1, (void *)listen(fd, s->lim_fd), "listen");
  (s->fds[fd]).type = FD_SERV;
  (s->fds[fd]).fct_read = accept_client;
}

int		init(t_stck *s, int port)
{
  struct rlimit	r;
  int		i;

  i = 0;
  if (port < 0 || port > 65535)
    return (-1);
  s->port = port;
  X((void *)-1, (void *)getrlimit(RLIMIT_NOFILE, &r), "getrlimit");
  s->lim_fd = r.rlim_cur;
  s->fds = Xmalloc(s->lim_fd * sizeof(t_fd));
  s->channel = NULL;
  return (0);
}
