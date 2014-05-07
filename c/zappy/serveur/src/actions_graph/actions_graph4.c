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

char	*get_pdr(t_stck *s, t_gparam *res)
{
  char	*tmp;

  (void)s;
  tmp = Xmalloc(32 * sizeof(char));
  sprintf(tmp, "pdr %d %d", res->n, res->i);
  return (tmp);
}

char	*get_pgt(t_stck *s, t_gparam *res)
{
  char	*tmp;

  (void)s;
  tmp = Xmalloc(32 * sizeof(char));
  sprintf(tmp, "pgt %d %d", res->n, res->i);
  return (tmp);
}

char	*get_enw(t_stck *s, t_gparam *res)
{
  char	*tmp;

  tmp = Xmalloc(64 * sizeof(char));
  sprintf(tmp, "enw %d %d %d %d",
	  res->e, res->n, s->fds[res->n].x, s->fds[res->n].y);
  return (tmp);
}

char	*get_oneint(char *s, int i)
{
  char	*tmp;

  tmp = Xmalloc(16 * sizeof(char));
  snprintf(tmp, 16, "%s %d", s, i);
  return (tmp);
}

char	*get_onestr(char *s, char *msg)
{
  char	*tmp;

  tmp = Xmalloc((strlen(s) + strlen(msg) + 2) * sizeof(char));
  sprintf(tmp, "%s %s", s, msg);
  return (tmp);
}
