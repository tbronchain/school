#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "serveur/serveur.h"
#include "serveur/cmd_serv.h"
#include "serveur/channel.h"
#include "serveur/send.h"
#include "serveur/lib.h"
#include "serveur/x.h"

void	add_sorted(t_chan **chan, t_chan *new, t_chan *tmp)
{
  while (tmp)
    {
      if (strcmp(tmp->name, new->name) > 0)
	{
	  new->prev = tmp->prev;
	  new->next = tmp;
	  if (tmp->prev)
	    tmp->prev->next = new;
	  tmp->prev = new;
	  if (tmp == *chan)
	    *chan = new;
	  return ;
	}
      tmp = tmp->next;
    }
  tmp = *chan;
  while (tmp->next)
    tmp = tmp->next;
  new->prev = tmp;
  tmp->next = new;
}

void		del_elem(t_chan **list, t_chan *del)
{
  t_chan	*tmp;

  if (*list == del)
    {
      tmp = (*list)->next;
      free(*list);
      *list = tmp;
      return ;
    }
  tmp = *list;
  while (tmp)
    {
      if (tmp == del)
	{
	  tmp->prev->next = tmp->next;
	  if (tmp->next)
	    tmp->next->prev = tmp->prev;
	  free(tmp);
	}
      tmp = tmp->next;
    }
}
