#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "main.h"
#include "actions_graph/event_actions.h"
#include "actions_ia/actions_ia.h"
#include "transfer/send.h"
#include "utils/x.h"

static int	get_case_from_view(int view, int pos)
{
  return (((pos + view * 2) % 8) + 1);
}

static int	trans_ang(float ang)
{
  if (ang >= REF)
    return (1);
  else if (ang <= -REF)
    return (-1);
  return (0);
}

static int	get_case(t_fd *b, int x, int y)
{
  int		cos;
  int		sin;
  float		h;

  h = sqrtf(pow(x, 2) + pow(y, 2));
  cos = trans_ang(x / h);
  sin = trans_ang(y / h);
  if (sin == -1 && cos == 0)
    return (get_case_from_view(b->view, 0));
  else if (sin == -1 && cos == 1)
    return (get_case_from_view(b->view, 1));
  else if (sin == 0 && cos == 1)
    return (get_case_from_view(b->view, 2));
  else if (sin == 1 && cos == 1)
    return (get_case_from_view(b->view, 3));
  else if (sin == 1 && cos == 0)
    return (get_case_from_view(b->view, 4));
  else if (sin == 1 && cos == -1)
    return (get_case_from_view(b->view, 5));
  else if (sin == 0 && cos == -1)
    return (get_case_from_view(b->view, 6));
  else if (sin == -1 && cos == -1)
    return (get_case_from_view(b->view, 7));
  return (1);
}

static int	get_rep(t_stck *s, t_fd *a, t_fd *b)
{
  int		x;
  int		y;

  x = a->x - b->x;
  x = (x > (s->map.x / 2)) ? x - s->map.x : x;
  x = (x < (-(s->map.x / 2))) ? x + s->map.x : x;
  y = a->y - b->y;
  y = (y > (s->map.y / 2)) ? y - s->map.y : y;
  y = (y < (-(s->map.y / 2))) ? y + s->map.y : y;
  return (get_case(b, x, y));
}

int	broadcast(t_stck *s, int fd, t_wait *t)
{
  char	*cmd;
  char	*tmp;
  int	k;
  int	i;

  cmd = t->cmd + 10;
  i = 3;
  tmp = Xmalloc(strlen(cmd) + 32);
  while (++i <= s->max_fd)
    {
      if (s->fds[i].type != FD_IA || i == fd)
	continue;
      k = get_rep(s, &(s->fds[fd]), &(s->fds[i]));
      memset(tmp, 0, strlen(cmd) + 32);
      sprintf(tmp, "message %d,%s", k, cmd);
      send_one(tmp, i, s);
    }
  send_one("ok", fd, s);
  event_broadcast(s, fd, cmd);
  return (0);
}

