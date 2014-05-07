#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_graph/actions_graph.h"
#include "actions_graph/check_action_graph.h"
#include "utils/lib.h"
#include "utils/x.h"

char	*get_pbc(t_stck *s, t_gparam *res)
{
  char	*tmp;

  if (res->n <= 0 || res->n >= s->lim_fd || !res->msg)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  tmp = Xmalloc((16 + strlen(res->msg)) * sizeof(char));
  sprintf(tmp, "pbc %d %s", res->n, res->msg);
  return (tmp);
}

char	*get_pic(t_stck *s, t_gparam *res)
{
  char	*tmp;
  int	i;

  if (res->n <= 0 || res->n >= s->lim_fd || !res->inc)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  tmp = Xmalloc((10 * res->inc_nb + 64) * sizeof(char));
  sprintf(tmp, "pic %d %d %d %d",
	  s->fds[res->n].x, s->fds[res->n].y, s->fds[res->n].level, res->n);
  i = 0;
  while (res->inc[i])
    sprintf(tmp, "%s %d", tmp, res->inc[i++]);
  return (tmp);
}

char	*get_pie(t_stck *s, t_gparam *res)
{
  char	*tmp;

  if (res->n <= 0 || res->n >= s->lim_fd)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  tmp = Xmalloc(64 * sizeof(char));
  sprintf(tmp,
	  "pie %d %d %d",
	  s->fds[res->n].x,
	  s->fds[res->n].y,
	  res->inc_res);
  return (tmp);
}

char	*get_pfk(t_stck *s, t_gparam *res)
{
  char	*tmp;

  if (res->n <= 0 || res->n >= s->lim_fd)
    return (strdup("sbp"));
  else if (s->fds[res->n].type != FD_IA)
    return (strdup("sbp"));
  tmp = Xmalloc(16 * sizeof(char));
  sprintf(tmp, "pfk %d", res->n);
  return (tmp);
}
