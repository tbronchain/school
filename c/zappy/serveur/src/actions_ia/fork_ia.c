#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "actions_ia/incant_ia.h"
#include "actions_ia/check_action_ia.h"
#include "actions_ia/actions_ia.h"
#include "actions_ia/actions_ia_2.h"
#include "actions_ia/fork_ia.h"
#include "transfer/send.h"
#include "utils/free.h"
#include "utils/lib.h"
#include "utils/list.h"
#include "transfer/funct_write.h"
#include "utils/timeout.h"
#include "utils/x.h"
#include "actions_graph/event_actions.h"
#include "utils/check_team.h"

t_egg	*add_egg_in_list(t_egg **begin, t_egg *new)
{
  t_egg	*tmp;
  t_egg	*save;

  if (!(*begin))
    return ((*begin = new));
  tmp = *begin;
  while (tmp)
    {
      save = tmp;
      if (tmp->id > new->id)
	{
	  new->prev = tmp->prev;
	  new->next = tmp;
	  if (tmp->prev)
	    tmp->prev->next = new;
	  else
	    *begin = new;
	  return ((tmp->prev = new));
	}
      tmp = tmp->next;
    }
  new->prev = save;
  return ((save->next = new));
}

void	del_egg_in_list(t_egg **begin, t_egg *del, t_stck *s)
{
  t_egg	*tmp;

  mod_team_c(s->teams_list, del->team, 1);
  if (*begin == del)
    {
      *begin = (*begin)->next;
      if (*begin)
	(*begin)->prev = NULL;
      return ;
    }
  tmp = (*begin)->next;
  while (tmp)
    {
      if (tmp == del)
	{
	  if (tmp->prev)
	    tmp->prev->next = tmp->next;
	  if (tmp->next)
	    tmp->next->prev = tmp->prev;
	  free(tmp);
	  return ;
	}
      tmp = tmp->next;
    }
}

int	del_egg(t_stck *s, int egg_id, int flag)
{
  t_egg	*tmp;

  tmp = s->egg;
  if (tmp)
    {
      while (tmp->id != egg_id)
	{
	  tmp = tmp->next;
	  if (!tmp)
	    return (0);
	}
      if (flag == 1)
	event_egg(s, "ebo", tmp->id);
      else
	event_egg(s, "edi", tmp->id);
      del_egg_in_list(&(s->egg), tmp, s);
    }
  return (0);
}

int			set_timeout_for_egg(t_stck *s,
				    int fd,
				    int pause,
				    int (*funct_wait)())
{
  t_wait		*new;
  struct timeval	tp;

  new = Xmalloc(sizeof(t_wait));
    gettimeofday(&tp, NULL);
  new->fd = fd;
  new->sec = tp.tv_sec + (pause / 1000000)
    + ((tp.tv_usec + (pause % 1000000)) / 1000000);
  new->usec = (tp.tv_usec + pause) % 1000000;
  new->funct_wait = funct_wait;
  new->id = s->max_egg;
  new->type = FD_EGG;
  return ((int)add_in_list(&(s->timeout), new));
}

int	egg_born(t_stck *s, int egg_id)
{
  t_egg	*tmp;

  tmp = s->egg;
  if (tmp)
    while (tmp->id != egg_id)
      {
	tmp = tmp->next;
	if (!tmp)
	  break;
      }
  tmp->status = 1;
  tmp->death = (t_wait *)set_timeout_for_egg(s, egg_id, (1260 * 1000000)
				     / s->t, del_egg);
  mod_team_c(s->teams_list, tmp->team, 1);
  event_egg(s, "eht", tmp->id);
  return (0);
}
