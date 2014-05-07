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

void		event_incant(t_stck *s, int fd, int *players)
{
  char		*tmp;
  t_gparam	res;
  int		i;

  i = 0;
  res.n = fd;
  res.inc = players;
  while (players[i++]);
  res.inc_nb = i;
  send_graphic((tmp = get_pic(s, &res)), s);
  free(tmp);
}

void		event_end_incant(t_stck *s, int fd, int *players, int flag)
{
  char		*tmp;
  t_gparam	res;
  int		i;

  res.n = fd;
  res.inc_res = flag;
  send_graphic((tmp = get_pie(s, &res)), s);
  free(tmp);
  i = 0;
  while (players[i])
    {
      res.n = i++;
      send_graphic((tmp = get_plv(s, &res)), s);
      free(tmp);
    }
}

void		event_end_incant_res(t_stck *s, int *move)
{
  char		*tmp;
  t_gparam	res;
  int		i;

  i = 0;
  while (move[i])
    {
      res.x = move[i] % s->map.x;
      res.y = move[i] / s->map.x;
      send_graphic((tmp = get_bct(s, &res)), s);
      free(tmp);
      i++;
    }
}

void		event_end_fork(t_stck *s, int fd, t_egg *new)
{
  char		*tmp;
  t_gparam	res;

  res.n = fd;
  res.e = new->id;
  send_graphic((tmp = get_enw(s, &res)), s);
  free(tmp);
}

void		event_egg(t_stck *s, char *cmd, int id)
{
  char		*tmp;

  send_graphic((tmp = get_oneint(cmd, id)), s);
  free(tmp);
}
