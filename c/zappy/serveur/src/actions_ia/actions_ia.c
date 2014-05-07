#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_ia/view_ia.h"
#include "actions_ia/utils_ia.h"
#include "actions_graph/actions_graph.h"
#include "utils/lib.h"
#include "utils/x.h"
#include "utils/check_team.h"
#include "transfer/send.h"

int		make_view(t_stck *s, int fd)
{
  t_view	v;

  bzero(&v, sizeof(v));
  update_players_location(s, fd);
  get_alloc_view(s, fd, &v);
  v.view_content = Xmalloc((v.alloc_len) * sizeof(v.view_content));
  strcat(v.view_content, "{");
  get_view_content(s, &v, fd);
  strcat(v.view_content, "}");
  send_one(v.view_content, fd, s);
  free(v.view_content);
  return (0);
}

int		move_left(t_stck *s, int fd)
{
  t_gparam	res;
  char		*tmp;

  s->fds[fd].view = (!s->fds[fd].view) ? GAUCHE : (s->fds[fd].view - 1);
  send_one("ok", fd, s);
  res.n = fd;
  send_graphic((tmp = get_ppo(s, &res)), s);
  free(tmp);
  return (0);
}

int		move_right(t_stck *s, int fd)
{
  t_gparam	res;
  char		*tmp;

  s->fds[fd].view = (s->fds[fd].view + 1) % 4;
  send_one("ok", fd, s);
  res.n = fd;
  send_graphic((tmp = get_ppo(s, &res)), s);
  free(tmp);
  return (0);
}

int		move_forward(t_stck *s, int fd)
{
  t_gparam	res;
  char		*tmp;

  if (s->fds[fd].view == HAUT || s->fds[fd].view == BAS)
    {
      if (s->fds[fd].view == HAUT)
	s->fds[fd].y = (s->fds[fd].y - 1) >= 0
	  ? (s->fds[fd].y - 1) : s->map.y + (s->fds[fd].y - 1);
      else
	s->fds[fd].y = (s->fds[fd].y + 1) % s->map.y;
    }
  else
    {
      if (s->fds[fd].view == DROITE)
	  s->fds[fd].x = (s->fds[fd].x + 1) % s->map.x;
      else
	s->fds[fd].x = (s->fds[fd].x - 1) >= 0
	  ? (s->fds[fd].x - 1) : s->map.x + (s->fds[fd].x - 1);
    }
  send_one("ok", fd, s);
  res.n = fd;
  send_graphic((tmp = get_ppo(s, &res)), s);
  free(tmp);
  return (0);
}

int	connect_nbr(t_stck *s, int fd)
{
  char	tmp[16];

  memset(tmp, 0, 16);
  sprintf(tmp, "%d", get_team_c(s->teams_list, s->fds[fd].team)
	  - check_team_nb(s, fd, s->fds[fd].team));
  send_one(tmp, fd, s);
  return (0);
}
