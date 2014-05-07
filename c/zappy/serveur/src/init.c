#include <sys/types.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "main.h"
#include "colors.h"
#include "init.h"
#include "utils/free.h"
#include "utils/x.h"
#include "accept_client.h"

static void	set_opt(int fd)
{
  int		flag;

  flag = 1;
  if (SO_NOSIGPIPE)
    X((void *)-1, (void *)setsockopt
      (fd, SOL_SOCKET, SO_NOSIGPIPE, (void *)&flag,
       sizeof(flag)), "setsockopt");
  flag = 1;
  _X((void *)-1, (void *)setsockopt
     (fd, SOL_SOCKET, SO_REUSEADDR, (void *)&flag, sizeof(flag)),
     "setsockopt");
}

static void	init_teams(t_teams **list, char **teams, int c)
{
  t_teams	*new;
  int		j;

  j = 0;
  while (teams[j])
    {
      new = Xmalloc(sizeof(*new));
      new->team = teams[j];
      new->c = c;
      new->next = *list;
      *list = new;
      j++;
    }
}

void			init(t_stck *s)
{
  struct protoent	*p;
  struct sockaddr_in	sin;
  int			fd;

  s->fds = Xmalloc(s->lim_fd * sizeof(t_fd));
  p = (struct protoent *)X(NULL, getprotobyname("tcp"), "getprotobyname");
  fd = (int)X((void *)-1, (void *)socket(PF_INET, SOCK_STREAM, p->p_proto),
	      "socket");
  set_opt(fd);
  sin.sin_family = AF_INET;
  sin.sin_family = AF_INET;
  sin.sin_port = htons(s->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  X((void *)-1, (void *)bind(fd, (struct sockaddr *)&sin, sizeof(sin)), "bind");
  X((void *)-1, (void *)listen(fd, s->lim_fd), "listen");
  (s->fds[fd]).type = FD_SERV;
  (s->fds[fd]).fct_read = accept_client;
  s->map.map = Xmalloc(((s->map.x * s->map.y) + 1) * sizeof(t_case));
  srand(time(NULL) * getpid());
  init_teams(&(s->teams_list), s->teams, s->max_tclient);
}

int		end(t_stck *s, int val)
{
  t_wait	*tmp;

  printf(BLUE2"\nTerminating...%s\n\n", DEFAULT);
  _X((void *)-1, (void *)shutdown(3, SHUT_RD), "shutdown");
  _X((void *)-1, (void *)close(3), "close");
  free_tab(s->teams);
  free(s->fds);
  while (s->timeout)
    {
      tmp = s->timeout;
      s->timeout = s->timeout->next;
      free(tmp);
    }
  free(s->map.map);
  if (val == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
