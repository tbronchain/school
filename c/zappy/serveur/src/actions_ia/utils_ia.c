#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_ia/view_ia.h"
#include "actions_ia/coord_ia.h"
#include "actions_ia/utils_ia.h"
#include "utils/lib.h"
#include "utils/x.h"
#include "utils/check_team.h"
#include "transfer/send.h"

extern t_ressource	gl_res[];

void	expulse_player(t_stck *s, int fd)
{
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
	s->fds[fd].x = (s->fds[fd].x - 1) > 0
	  ? (s->fds[fd].x - 1) : s->map.x + (s->fds[fd].x - 1);
    }
}

void			get_food(t_stck *s, int fd, int *val)
{
  int			left;
  struct timeval	tv;

  gettimeofday(&tv, NULL);
  left = s->fds[fd].death->sec - tv.tv_sec;
  if (left > 0)
    *val = left * 10 * s->t / 1260;
  else
    *val = 0;
}

int	get_case_alloc_len(t_stck *s, t_view *v)
{
  int		*val;
  int		*tmp;
  int		type;
  int		alloc_len;

  type = 0;
  alloc_len = 0;
  tmp = verif_coord(s, v);
  while (type  < 7)
    {
      val = &(s->map.map[tmp[0] + tmp[1] * s->map.x].food) + type;
      if (*val)
	  alloc_len += 11 * (*val);
      else
	alloc_len += 11;
      type++;
    }
  return (alloc_len);
}

void	get_ressource_name(int type, t_view *v)
{
  int	j;

  j = 0;
  while (gl_res[j].type)
    {
      if (gl_res[j].type == (type + 1))
	{
	  strcat(v->case_content, " ");
	  strcat(v->case_content, gl_res[j].name);
	  break;
	}
	j++;
    }
}

void	update_players_location(t_stck *s, int fd)
{
  int	i;
  int	j;
  char	*players;

  i = -1;
  players = Xmalloc((s->map.x * s->map.y) * sizeof(players));
  bzero(players, (s->map.x * s->map.y));
  while (++i <= s->max_fd)
    if (s->fds[i].team && i != fd)
      players[s->fds[i].x + s->fds[i].y * s->map.x]++;
  i = 0;
  while (i < s->map.x)
    {
      j = -1;
      while (++j < s->map.y)
	s->map.map[i + j * s->map.x].players = players[i + j * s->map.x];
      i++;
    }
  free(players);
}
