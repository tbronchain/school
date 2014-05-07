#include <sys/time.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur/serveur.h"
#include "serveur/init.h"
#include "serveur/client_read.h"
#include "serveur/lib.h"
#include "serveur/list.h"
#include "serveur/free.h"
#include "serveur/x.h"

static void	init_fd(t_stck *s)
{
  int		i;

  i = 0;
  s->max_fd = 0;
  FD_ZERO(&(s->fd_read));
  while (i < s->lim_fd)
    {
      if ((s->fds[i]).type != FD_FREE)
	{
	  FD_SET(i, &(s->fd_read));
	  s->max_fd = ((s->max_fd > i) ? s->max_fd : i);
	}
      i++;
    }
}

static void	del_chan(t_stck *s)
{
  t_chan	*tmp;
  int		i;
  int		flag;

  tmp = s->channel;
  while (tmp)
    {
      i = 0;
      flag = 0;
      while (i < (s->max_fd + 1))
	{
	  if (s->fds[i].type == FD_CLIENT &&
	      !strcmp(s->fds[i].channel, tmp->name))
	    flag++;
	  i++;
	}
      if (!flag)
	del_elem(&(s->channel), tmp);
      tmp = tmp->next;
    }
}

static void		loop(t_stck *s)
{
  struct timeval	tv;
  int			i;

  while (1)
    {
      init_fd(s);
      tv.tv_sec = SELECT_TIMEOUT;
      tv.tv_usec = 0;
      s->queue = (int)X((void *)-1, (void *)select
			(s->max_fd + 1, &(s->fd_read),
			 NULL, NULL, &tv), "select");
      i = 0;
      while (i < s->lim_fd && s->queue > 0)
	{
	  if (FD_ISSET(i, &(s->fd_read)))
	    {
	      (s->fds[i]).fct_read(s, i);
	      s->queue--;
	    }
	  i++;
	}
      del_chan(s);
    }
}

int		main(int ac, char **av)
{
  t_stck	s;

  if (ac != 2)
    {
      fputs("Syntax error.\nusage: serveur <port>\n", stderr);
      return (EXIT_FAILURE);
    }
  else if (init(&s, atoi(av[1])))
    {
      fputs("Syntax error.\nport must be between 0 and 65535\n", stderr);
      return (EXIT_FAILURE);
    }
  launch_serv(&s);
  loop(&s);
  free_list(&(s.channel));
  free(s.fds);
  return (EXIT_SUCCESS);
}
