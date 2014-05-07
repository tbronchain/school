#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_graph/actions_graph.h"
#include "actions_graph/check_action_graph.h"
#include "transfer/send.h"
#include "utils/free.h"
#include "utils/lib.h"
#include "utils/x.h"

t_cmd_graph	gl_graph[] =
  {
    {"msz", get_msz},
    {"bct", get_bct},
    {"mct", get_mct},
    {"tna", get_tna},
    {"ppo", get_ppo},
    {"plv", get_plv},
    {"pin", get_pin},
    {"sgt", get_sgt},
    {"sst", get_sst},
    {0, 0}
  };

int		exec_graph(t_stck *s, int fd, char *buf, char *(*funct)())
{
  t_gparam	res;
  char		**cmd;
  char		*tmp;

  memset(&res, 0, sizeof(res));
  cmd = str_to_wordtab(buf, ' ');
  if (cmd[1])
    {
      if (!cmd[2])
	res.n = atoi(cmd[1]);
      else
	{
	  res.x = atoi(cmd[1]);
	  res.y = atoi(cmd[2]);
	}
    }
  res.fd = fd;
  if ((tmp = funct(s, &res)))
    {
      send_one(tmp, fd, s);
      free(tmp);
    }
  free_tab(cmd);
  return (0);
}

int	check_action_graph(t_stck *s, int fd, char *buf)
{
  char	**cmd;
  int	i;

  i = 0;
  if (!(cmd = verif_wordtab(buf, ' ')))
    return (-1);
  while (gl_graph[i].cmd)
    {
      if (!strcmp(cmd[0], gl_graph[i].cmd))
	{
	  s->fds[fd].err = 0;
	  free_tab(cmd);
	  return (exec_graph(s, fd, buf, gl_graph[i].funct));
	}
      i++;
    }
  s->fds[fd].err++;
  send_one("suc", fd, s);
  free_tab(cmd);
  return (0);
}
