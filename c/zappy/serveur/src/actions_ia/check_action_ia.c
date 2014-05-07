#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_graph/actions_graph.h"
#include "actions_graph/event_actions.h"
#include "actions_ia/incant_ia.h"
#include "actions_ia/fork_ia.h"
#include "actions_ia/check_action_ia.h"
#include "actions_ia/actions_ia.h"
#include "actions_ia/actions_ia_2.h"
#include "transfer/send.h"
#include "utils/free.h"
#include "utils/lib.h"
#include "utils/list.h"
#include "transfer/funct_write.h"
#include "utils/timeout.h"
#include "utils/x.h"

t_cmd_ia	gl_ia[] =
  {
    {"avance", set_timeout, 7, move_forward},
    {"droite", set_timeout, 7, move_right},
    {"gauche", set_timeout, 7, move_left},
    {"voir", set_timeout, 7, make_view},
    {"inventaire", set_timeout, 1, get_invent},
    {"prend", set_timeout, 7, take_object},
    {"pose", set_timeout, 7, drop_object},
    {"expulse", set_timeout, 7, make_expulse},
    {"broadcast", set_timeout, 7, broadcast},
    {"incantation", set_incantation, 300, finish_incantation},
    {"fork", set_fork, 42, set_egg},
    {"connect_nbr", set_timeout, 0, connect_nbr},
    {0, 0, 0, 0}
  };

extern t_incant_token	gl_inc_tok[];

int	finish_incantation(t_stck *s, int fd)
{
  int	i;
  int	*players;
  int	flag;
  int	res;

  i = -1;
  flag = 1;
  players = get_players_from_case(s, fd);
  res = check_ressource_for_incant(s, fd);
  while (players[++i])
    flag = s->fds[players[i]].level == s->fds[fd].level ? 1 : 0;
  if (flag && (i + 1) == gl_inc_tok[s->fds[fd].level - 1].nb_players && res)
    {
      upgrade_level(s, fd, players);
      event_end_incant(s, fd, players, 1);
      players = set_ressources(s, fd, players);
      event_end_incant_res(s, players);
    }
  else
    {
      send_one("ko", fd, s);
      event_end_incant(s, fd, players, 0);
    }
  free(players);
  return (0);
}

int	set_incantation(t_stck *s, int fd, int pause, int (*funct)())
{
  int	i;
  int	*players;
  int	flag;
  int	ressource;

  i = 0;
  flag = 1;
  players = get_players_from_case(s, fd);
  ressource = check_ressource_for_incant(s, fd);
  while (players[i])
    {
      flag = s->fds[players[i]].level == s->fds[fd].level ? 1 : 0;
      i++;
    }
  if (flag && (i + 1) == gl_inc_tok[s->fds[fd].level - 1].nb_players
      && ressource)
    {
      set_timeout(s, fd, pause, funct);
      send_one("elevation en cours", fd, s);
      event_incant(s, fd, players);
    }
  else
    send_one("ko", fd, s);
  free(players);
  return (0);
}

int	set_egg(t_stck *s, int fd)
{
  t_egg	*new;

  new = Xmalloc(sizeof(t_egg));

  s->max_egg = s->max_egg == 0 ? 1 : (s->max_egg + 1);
  new->id = s->max_egg;
  new->status = 0;
  new->x = s->fds[fd].x;
  new->y = s->fds[fd].y;
  strcpy(new->team, s->fds[fd].team);
  add_egg_in_list(&(s->egg), new);
  set_timeout_for_egg(s, s->max_egg, 600000000 / s->t, egg_born);
  event_end_fork(s, fd, new);
  return (0);
}

int	set_fork(t_stck *s, int fd, int pause, int (*funct)())
{
  char	*tmp;

  send_graphic((tmp = get_oneint("pfk", fd)), s);
  set_timeout(s, fd, pause, funct);
  send_one("ok", fd, s);
  free(tmp);
  return (0);
}

int	check_action_ia(t_stck *s, int fd, char *buf)
{
  char	**cmd;
  int	i;
  int	pause;

  if (!(cmd = verif_wordtab(buf, ' ')))
    {
      s->fds[fd].err++;
      set_timeout(s, fd, 1, send_ko);
      return (-1);
    }
  i = -1;
  while (gl_ia[++i].cmd)
    if (!strcmp(cmd[0], gl_ia[i].cmd))
      {
	s->fds[fd].err = 0;
	free_tab(cmd);
	pause = !(pause = 1000000 * gl_ia[i].param / s->t) ? 1 : pause;
	return (gl_ia[i].funct(s, fd, pause, gl_ia[i].funct_wait));
      }
  s->fds[fd].err++;
  free_tab(cmd);
  set_timeout(s, fd, 1, send_ko);
  return (0);
}
