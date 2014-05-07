#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/x.h"
#include "transfer/funct_write.h"
#include "transfer/send.h"
#include "utils/kick.h"
#include "utils/timeout.h"
#include "utils/free.h"
#include "actions_ia/init_ia.h"
#include "actions_ia/fork_ia.h"
#include "utils/check_team.h"
#include "actions_graph/actions_graph.h"

static int	get_egg_param(t_stck *s, int fd, t_egg *egg)
{
  char		tmp[32];

  s->fds[fd].view = RANDOM(0, 3);
  s->fds[fd].x = egg->x;
  s->fds[fd].y = egg->y;
  s->fds[fd].level = 1;
  s->fds[fd].invent.food = 10;
  s->fds[fd].team = egg->team;
  s->fds[fd].buf_read = strdup("MORT");
  s->fds[fd].death = egg->death;
  s->fds[fd].death->fd = fd;
  s->fds[fd].death->funct_wait = funct_dead;
  s->fds[fd].buf_read = xfree(s->fds[fd].buf_read);
  del_egg(s, egg->id, 1);
  memset(tmp, 0, 32);
  sprintf(tmp, "%d %d", s->map.x, s->map.y);
  send_one(tmp, fd, s);
  return (0);
}

static int	get_default_param(t_stck *s, int fd)
{
  char		tmp[32];

  s->fds[fd].x = RANDOM(1, (s->map.x - 1));
  s->fds[fd].y = RANDOM(1, (s->map.y - 1));
  s->fds[fd].view = RANDOM(0, 3);
  s->fds[fd].level = 1;
  s->fds[fd].invent.food = 10;
  s->fds[fd].buf_read = strdup("MORT");
  s->fds[fd].death = (t_wait *)set_timeout(s, fd, (1260 * 1000000)
					   / s->t, funct_dead);
  s->fds[fd].buf_read = xfree(s->fds[fd].buf_read);
  memset(tmp, 0, 32);
  sprintf(tmp, "%d %d", s->map.x, s->map.y);
  send_one(tmp, fd, s);
  return (0);
}

t_egg	*check_egg(t_stck *s)
{
  t_egg	*tmp;

  tmp = s->egg;
  if (tmp)
    while (tmp)
      {
	if (tmp->id)
	  return (tmp);
	if (!tmp)
	  break;
      }
  return (0);
}

static int	error_team(t_stck *s, int fd)
{
  char		tmp[32];

  send_now("0", s, fd);
  memset(tmp, 0, 32);
  sprintf(tmp, "%d %d", s->map.x, s->map.y);
  send_now(tmp, s, fd);
  return (-2);
}

int		init_ia(t_stck *s, int fd, char *buf)
{
  char		*team;
  t_egg		*egg;
  char		tmp[32];
  t_gparam	res;
  int		r;

  if (!(team = check_team_names(s, buf)))
    return (-1);
  memset(tmp, 0, 32);
  s->fds[fd].team = team;
  if (check_team_nb(s, fd, buf) > get_team_c(s->teams_list, s->fds[fd].team))
    return (error_team(s, fd));
  sprintf(tmp, "%d", get_team_c(s->teams_list, s->fds[fd].team)
	  - check_team_nb(s, fd, buf));
  send_one(tmp, fd, s);
  egg = (t_egg *)check_egg(s);
  r = (egg && egg->status)
    ? get_egg_param(s, fd, egg) : get_default_param(s, fd);
  res.n = fd;
  send_graphic((team = get_pnw(s, &res)), s);
  return ((int)xfree(team));
}
