#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/x.h"
#include "transfer/send.h"
#include "utils/free.h"
#include "actions_graph/actions_graph.h"
#include "actions_graph/event_actions.h"

void		event_broadcast(t_stck *s, int fd, char *msg)
{
  char		*tmp;
  t_gparam	res;

  res.n = fd;
  res.msg = msg;
  send_graphic((tmp = get_pbc(s, &res)), s);
  free(tmp);
}

void		event_expluse(t_stck *s, int fd, int *players)
{
  char		*tmp;
  t_gparam	res;
  int		i;

  i = 0;
  send_graphic((tmp = get_oneint("pex", fd)), s);
  free(tmp);
  while (players[i])
    {
      res.n = i;
      send_graphic((tmp = get_ppo(s, &res)), s);
      free(tmp);
      i++;
    }
}

void		event_take(t_stck *s, int fd, int type)
{
  char		*tmp;
  t_gparam	res;

  res.n = fd;
  res.i = type;
  res.x = s->fds[fd].x;
  res.y = s->fds[fd].y;
  send_graphic((tmp = get_pgt(s, &res)), s);
  free(tmp);
  send_graphic((tmp = get_pin(s, &res)), s);
  free(tmp);
  send_graphic((tmp = get_bct(s, &res)), s);
  free(tmp);
}

void		event_drop(t_stck *s, int fd, int type)
{
  char		*tmp;
  t_gparam	res;

  res.n = fd;
  res.i = type;
  res.x = s->fds[fd].x;
  res.y = s->fds[fd].y;
  send_graphic((tmp = get_pdr(s, &res)), s);
  free(tmp);
  send_graphic((tmp = get_pin(s, &res)), s);
  free(tmp);
  send_graphic((tmp = get_bct(s, &res)), s);
  free(tmp);
}
