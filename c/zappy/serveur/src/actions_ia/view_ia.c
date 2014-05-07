#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_ia/view_ia.h"
#include "actions_ia/coord_ia.h"
#include "actions_ia/actions_ia_2.h"
#include "actions_ia/utils_ia.h"
#include "utils/lib.h"
#include "utils/x.h"

static void	get_case_content(t_stck *s, t_view *v)
{
  int		i;
  int		*val;
  int		*tmp;
  int		type;

  type = -1;
  v->case_content = Xmalloc(v->alloc_len * sizeof(v->case_content));
  tmp = verif_coord(s, v);
  while (++type  < 8)
    {
      val = &(s->map.map[tmp[0] + tmp[1] * s->map.x].food) + type;
      i = 0;
      if (*val > 0)
	while (++i <= *val)
	  get_ressource_name(type, v);
    }
  strcat(v->view_content, v->case_content);
  free(v->case_content);
  free(tmp);
}

static void	get_line_content(t_stck *s, t_view *v, int fd)
{
  if (s->fds[fd].view == HAUT || s->fds[fd].view == DROITE)
    {
      while (v->first_coord[v->coord_type] <= v->end_coord[v->coord_type])
	{
	  get_case_content(s, v);
	  strcat(v->view_content, ",");
	  increment_coord_by_view(s, fd, v);
	}
    }
  else
    {
      while (v->first_coord[v->coord_type] >= v->end_coord[v->coord_type])
	{
	  get_case_content(s, v);
	  strcat(v->view_content, ",");
	  increment_coord_by_view(s, fd, v);
	}
    }
}

void	get_view_content(t_stck *s, t_view *v, int fd)
{
  int	i;

  i = 0;
  v->is_first = 0;
  v->first_coord = get_player_view_case(s, fd, i, 1);
  get_case_content(s, v);
  strcat(v->view_content, ",");
  while (++i <= s->fds[fd].level)
    {
      v->first_coord = get_player_view_case(s, fd, i, 0);
      v->end_coord = get_end_by_lvl(s, fd, i, v->first_coord);
      v->coord_type = v->end_coord[0] == v->first_coord[0] ? 1 : 0;
      v->coord_type = v->end_coord[1] == v->first_coord[1] ? 0 : 1;
      get_line_content(s, v, fd);
      free (v->end_coord);
      free (v->first_coord);
    }
}

static void	get_line_alloc(t_stck *s, t_view *v, int fd)
{
  if (s->fds[fd].view == HAUT || s->fds[fd].view == DROITE)
    {
      while (v->first_coord[v->coord_type] <= v->end_coord[v->coord_type])
	{
	  v->alloc_len += get_case_alloc_len(s, v);
	  increment_coord_by_view(s, fd, v);
	}
    }
  else
    {
      while (v->first_coord[v->coord_type] >= v->end_coord[v->coord_type])
	{
	  v->alloc_len += get_case_alloc_len(s, v);
	  increment_coord_by_view(s, fd, v);
	}
    }
}

void	get_alloc_view(t_stck *s, int fd, t_view *v)
{
  int	i;

  i = 0;
  v->alloc_len = 0;
  while (++i <= s->fds[fd].level)
    {
      v->first_coord = get_player_view_case(s, fd, i, 0);
      v->end_coord = get_end_by_lvl(s, fd, i, v->first_coord);
      v->coord_type = v->end_coord[0] == v->first_coord[0] ? 1 : 0;
      v->coord_type = v->end_coord[1] == v->first_coord[1] ? 0 : 1;
      get_line_alloc(s, v, fd);
    }
  free(v->first_coord);
  free(v->end_coord);
}
