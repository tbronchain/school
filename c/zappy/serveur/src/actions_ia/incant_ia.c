#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_ia/incant_ia.h"
#include "actions_ia/check_action_ia.h"
#include "actions_ia/actions_ia.h"
#include "actions_ia/actions_ia_2.h"
#include "transfer/send.h"
#include "utils/free.h"
#include "utils/lib.h"
#include "utils/timeout.h"
#include "utils/x.h"

extern t_incant_token	gl_inc_tok[];

int	*set_ressources(t_stck *s, int fd, int *players)
{
  int	i;
  int	type;
  int	*val;

  i = 0;
  type = -1;
  bzero(players, s->lim_fd);
  players[0] = s->fds[fd].x + s->fds[fd].y * s->map.x;
  while (++type < 6)
    {
      val = &(s->map.map[s->fds[fd].x + s->fds[fd].y * s->map.x].linemate)
	+ type;
      if (*val)
	{
	  (*val)--;
	  players[i] = RANDOM(0, s->map.x) + RANDOM(0, s->map.y) * s->map.x;
	  val = &(s->map.map[players[i++]].linemate) + type;
	  (*val)++;
	}
    }
  return (players);
}

int	check_ressource_for_incant(t_stck *s, int fd)
{
  int	needs;
  int	type;
  int	flag;
  int	*case_val;
  int	*need_val;

  type = 0;
  flag = 0;
  needs = 0;
  while (gl_inc_tok[needs].level != (s->fds[fd].level + 1))
    needs++;
  while (type < 6)
    {
      case_val = &(s->map.map[s->fds[fd].x + s->fds[fd].y * s->map.x].linemate)
	+ type;
      need_val = &(gl_inc_tok[needs].linemate) + type;
      flag += *case_val == *need_val ? 1 : 0;
      type++;
    }
  if (flag == 6)
    return (1);
  return (0);
}

int	*get_players_from_case(t_stck *s, int fd)
{
  int	*players;
  int	i;
  int	j;
  int	flag;

  i = 0;
  j = 0;
  players = Xmalloc(s->lim_fd * sizeof(*players));
  while (i <= s->max_fd)
    {
      flag = 0;
      flag += s->fds[i].type != FD_FREE ? 1 : 0;
      flag += s->fds[i].type == FD_IA ? 1 : 0;
      flag += s->fds[i].x == s->fds[fd].x ? 1 : 0;
      flag += s->fds[i].y == s->fds[fd].y ? 1 : 0;
      flag += i != fd ? 1 : 0;
      if (flag == 5)
	players[j++] = i;
      i++;
    }
  return (players);
}

void	upgrade_level(t_stck *s, int fd, int *players)
{
  char	*tmp;
  int	i;

  i = -1;
  tmp = Xmalloc(4096 * sizeof(tmp));
  s->fds[fd].level++;
  sprintf(tmp, "niveau actuel : %d", s->fds[fd].level);
  send_one(tmp, fd, s);
  while (players[++i])
    {
      s->fds[players[i]].level++;
      send_one(tmp, players[i], s);
    }
  free(tmp);
}
