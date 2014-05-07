#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_ia/view_ia.h"
#include "utils/lib.h"
#include "utils/x.h"

int	*verif_coord(t_stck *s, t_view *v)
{
  int	*tmp;

  tmp = Xmalloc(2 * sizeof(tmp));
  tmp[0] = (v->first_coord[0] % s->map.x) >= 0
    ? (v->first_coord[0] % s->map.x) : v->first_coord[0];
  tmp[0] = v->first_coord[0] < 0
    ? s->map.x + (v->first_coord[0]) : tmp[0];
  tmp[1] = (v->first_coord[1] % s->map.y) >= 0
    ? (v->first_coord[1] % s->map.y) : v->first_coord[1];
  tmp[1] = v->first_coord[1] < 0 ?
    s->map.y + (v->first_coord[1]) : tmp[1];
  return (tmp);
}

void	increment_coord_by_view(t_stck *s, int fd, t_view *v)
{
  if (s->fds[fd].view == HAUT || s->fds[fd].view == BAS)
    {
      v->first_coord[0] += s->fds[fd].view == HAUT ? 1 : 0;
      v->first_coord[0] -= s->fds[fd].view == BAS ? 1 : 0;
    }
  else
    {
      v->first_coord[1] -= s->fds[fd].view == GAUCHE ? 1 : 0;
      v->first_coord[1] += s->fds[fd].view == DROITE ? 1 : 0;
    }
}

int	*get_player_view_case(t_stck *s, int fd, int level, int my_case)
{
  int	*coord;

  coord = Xmalloc(2 * sizeof(coord));
  if (my_case)
    {
      coord[0] = s->fds[fd].x;
      coord[1] = s->fds[fd].y;
      return (coord);
    }
  if (s->fds[fd].view == HAUT || s->fds[fd].view == BAS)
    {
      coord[0] = s->fds[fd].view == HAUT ? (s->fds[fd].x - level) : 0;
      coord[1] = s->fds[fd].view == HAUT ? (s->fds[fd].y - level) : 0;
      coord[0] = s->fds[fd].view == BAS ? (s->fds[fd].x + level) : coord[0];
      coord[1] = s->fds[fd].view == BAS ? (s->fds[fd].y + level) : coord[1];
    }
  else
    {
      coord[0] = s->fds[fd].view == DROITE ? (s->fds[fd].x + level) : 0;
      coord[1] = s->fds[fd].view == DROITE ? (s->fds[fd].y - level) : 0;
      coord[0] = s->fds[fd].view == GAUCHE ? (s->fds[fd].x - level) : coord[0];
      coord[1] = s->fds[fd].view == GAUCHE ? (s->fds[fd].y + level) : coord[1];
    }
  return (coord);
}

int	*get_end_by_lvl(t_stck *s, int fd, int level, int *coord)
{
  int	*end_coord;
  int	end_line;

  end_line = 0;
  end_coord = Xmalloc(2 * sizeof(end_coord));
  end_coord[0] = coord[0];
  end_coord[1] = coord[1];
  if (s->fds[fd].view == HAUT || s->fds[fd].view == GAUCHE)
    {
      end_line += level * 2;
      if (s->fds[fd].view == HAUT)
	end_coord[0] += end_line;
      else
	end_coord[1] -= end_line;
    }
  else
    {
      end_line = s->fds[fd].view == BAS ? end_line - (level * 2) : level * 2;
      if (s->fds[fd].view == BAS)
	end_coord[0] += end_line;
      else
	  end_coord[1] += end_line;
    }
  return (end_coord);
}
