#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/list.h"
#include "utils/x.h"

t_wait		*add_in_list(t_wait **begin, t_wait *new)
{
  t_wait	*tmp;
  t_wait	*save;

  if (!(*begin))
    return ((*begin = new));
  tmp = *begin;
  while (tmp)
    {
      save = tmp;
      if (tmp->sec > new->sec
	  || (tmp->sec == new->sec && tmp->usec >= new->usec))
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

void		del_in_list(t_wait **begin, t_wait *del)
{
  t_wait	*tmp;

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
	  if (tmp->cmd)
	    free(tmp->cmd);
	  free(tmp);
	  return ;
	}
      tmp = tmp->next;
    }
}

void		free_list(t_wait **begin)
{
  t_wait	*tmp;

  while (*begin)
    {
      tmp = (*begin)->next;
      if ((*begin)->cmd)
	free((*begin)->cmd);
      free(*begin);
       *begin = tmp;
    }
}
