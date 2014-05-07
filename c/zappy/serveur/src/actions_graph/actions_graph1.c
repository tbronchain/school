#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_graph/actions_graph.h"
#include "actions_graph/check_action_graph.h"
#include "transfer/send.h"
#include "utils/lib.h"
#include "utils/x.h"

char	*get_msz(t_stck *s, t_gparam *res)
{
  char	*tmp;

  (void)res;
  tmp = Xmalloc(16 * sizeof(char));
  sprintf(tmp, "msz %d %d", s->map.x, s->map.y);
  return (tmp);
}

char	*get_bct(t_stck *s, t_gparam *res)
{
  char	*tmp;
  int	*val;
  int	type;

  if (res->x < 0 || res->y < 0 || res->x >= s->map.x || res->y >= s->map.y)
    return (strdup("sbp"));
  type = 0;
  tmp = Xmalloc(128 * sizeof(char));
  sprintf(tmp, "bct %d %d", res->x, res->y);
  while (type < 7)
    {
      val = &(s->map.map[res->x + res->y * s->map.x].food) + type;
      sprintf(tmp, "%s %d", tmp, *val);
      type++;
    }
  return (tmp);
}

char	*get_mct(t_stck *s, t_gparam *res)
{
  char	*tmp;
  int	x;
  int	y;

  y = 0;
  while (y < s->map.y)
    {
      x = 0;
      while (x < s->map.x)
	{
	  res->x = x;
	  res->y = y;
	  tmp = get_bct(s, res);
	  send_one(tmp, res->fd, s);
	  free(tmp);
	  x++;
	}
      y++;
    }
  return (NULL);
}

char	*get_tna(t_stck *s, t_gparam *res)
{
  char	*tmp;
  int	i;

  i = 0;
  while (s->teams[i])
    {
      tmp = Xmalloc((strlen(s->teams[i]) + 5) * sizeof(char));
      sprintf(tmp, "tna %s", s->teams[i]);
      send_one(tmp, res->fd, s);
      free(tmp);
      i++;
    }
  return (NULL);
}

char	*get_ppo(t_stck *s, t_gparam *res)
{
  char	*tmp;

  if (res->n <= 0 || res->n >= s->lim_fd)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  tmp = Xmalloc(64 * sizeof(char));
  sprintf(tmp, "ppo %d %d %d %d", res->n, s->fds[res->n].x,
	  s->fds[res->n].y, s->fds[res->n].view + 1);
  return (tmp);
}
