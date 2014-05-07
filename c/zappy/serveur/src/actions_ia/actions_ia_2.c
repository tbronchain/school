#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/lib.h"
#include "utils/x.h"
#include "utils/check_team.h"
#include "actions_ia/get-put_ia.h"
#include "actions_ia/incant_ia.h"
#include "actions_ia/view_ia.h"
#include "actions_ia/actions_ia_2.h"
#include "actions_ia/utils_ia.h"
#include "actions_graph/event_actions.h"
#include "transfer/send.h"

extern t_ressource	gl_res[];

int	make_expulse(t_stck *s, int fd)
{
  int	i;
  int	*players;

  i = -1;
  players = get_players_from_case(s, fd);
  if (players[0] == 0)
    {
      send_one("ko", fd, s);
      return (0);
    }
  while (players[++i])
    {
      send_one("deplacement 1", players[i], s);
      expulse_player(s, fd);
    }
  send_one("ok", fd, s);
  event_expluse(s, fd, players);
  free(players);
  return (0);
}

int	get_invent(t_stck *s, int fd)
{
  char	*invent;
  char	*tmp;
  int	food;

  invent = Xmalloc(4096 * sizeof(invent));
  tmp = Xmalloc(4096 * sizeof(tmp));
  strcat(invent, "{");
  get_food(s, fd, &food);
  sprintf(tmp, "%s %d,", "nourriture", food);
  strcat(invent, tmp);
  get_invent_case(s, fd, invent, tmp);
  strcat(invent, "}");
  send_one(invent, fd, s);
  free(invent);
  return (0);
}

int	take_object(t_stck *s, int fd, t_wait *t)
{
  int	i;
  int	*val;
  int	type;

  i = -1;
  type = -1;
  while (++i < 7)
    if (strcmp(gl_res[i].name, t->cmd + get_object_name(t->cmd)) == 0)
      type = (gl_res[i].type - 1);
  val = &(s->map.map[s->fds[fd].x + s->fds[fd].y * s->map.x].food)
    + type;
  if (!(*val) || type == -1)
    send_one("ko", fd, s);
  else
    {
      if (type == 0)
	update_death_timer(s, fd, 1);
      (*val)--;
      val = &(s->fds[fd].invent.food) + type;
      (*val)++;
      send_one("ok", fd, s);
      event_take(s, fd, type);
    }
  return (0);
}

int	drop_object(t_stck *s, int fd, t_wait *t)
{
  int	i;
  int	*val;
  int	type;

  i = -1;
  type = -1;
  while (++i < 7)
    if (strcmp(gl_res[i].name, t->cmd + get_object_name(t->cmd)) == 0)
      type = (gl_res[i].type - 1);
  val = &(s->fds[fd].invent.food) + type;
  if (type == -1 || !(*val))
    send_one("ko", fd, s);
  else
    {
      if (type == 0)
	update_death_timer(s, fd, -1);
      (*val)--;
      val = &(s->map.map[s->fds[fd].x + s->fds[fd].y * s->map.x].food)
	+ type;
      (*val)++;
      send_one("ok", fd, s);
      event_drop(s, fd, type);
    }
  return (0);

}
