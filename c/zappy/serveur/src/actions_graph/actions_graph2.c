#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_graph/actions_graph.h"
#include "actions_graph/check_action_graph.h"
#include "actions_ia/view_ia.h"
#include "actions_ia/utils_ia.h"
#include "utils/lib.h"
#include "utils/x.h"

char	*get_plv(t_stck *s, t_gparam *res)
{
  char	*tmp;

  if (res->n <= 0 || res->n >= s->lim_fd)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  tmp = Xmalloc(32 * sizeof(char));
  sprintf(tmp, "plv %d %d", res->n, s->fds[res->n].level);
  return (tmp);
}

char	*get_pin(t_stck *s, t_gparam *res)
{
  char	*tmp;
  int	*val;
  int	type;
  int	r;

  if (res->n <= 0 || res->n >= s->lim_fd)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  type = 0;
  tmp = Xmalloc(128 * sizeof(char));
  sprintf(tmp, "pin %d %d %d", res->n, res->x, res->y);
  get_food(s, res->n, &r);
  sprintf(tmp, "%s %d", tmp, r);
  while (type < 6)
    {
      val = &(s->fds[res->n].invent.linemate) + type;
      sprintf(tmp, "%s %d", tmp, *val);
      type++;
    }
  return (tmp);
}

char	*get_sgt(t_stck *s, t_gparam *res)
{
  char	*tmp;

  (void)res;
  tmp = Xmalloc(16 * sizeof(char));
  sprintf(tmp, "sgt %d", s->t);
  return (tmp);
}

char	*get_sst(t_stck *s, t_gparam *res)
{
  if (res->n < 1)
    return (strdup("sbp"));
  s->t = res->n;
  return (get_sgt(s, res));
}

char	*get_pnw(t_stck *s, t_gparam *res)
{
  char	*tmp;
  t_fd	*p;

  if (res->n <= 0 || res->n >= s->lim_fd)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  p = &(s->fds[res->n]);
  tmp = Xmalloc((64 + strlen(p->team)) * sizeof(char));
  sprintf(tmp, "pnw %d %d %d %d %d %s",
	  res->n, p->x, p->y, p->view + 1, p->level, p->team);
  return (tmp);
}
