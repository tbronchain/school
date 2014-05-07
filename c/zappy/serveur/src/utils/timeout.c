#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/list.h"
#include "utils/timeout.h"
#include "utils/x.h"

static int	del_one_timeout(t_wait **timeout, int *wait)
{
  t_wait	*tmp;

  (*wait)--;
  if ((*timeout)->prev)
    (*timeout)->prev->next = (*timeout)->next;
  if ((*timeout)->next)
    (*timeout)->next->prev = (*timeout)->prev;
  tmp = *timeout;
  *timeout = (*timeout)->next;
  if (tmp->cmd)
    free(tmp->cmd);
  free(tmp);
  if (*timeout)
    return (1);
  return (0);
}

void		exec_timeout(t_stck *s)
{
  if (!s->timeout)
    return ;
  while (s->timeout->use == 1)
    {
      if ((s->fds[s->timeout->fd].type == FD_FREE
	  || s->fds[s->timeout->fd].id != s->timeout->id)
	  && s->timeout->type != FD_EGG)
	{
	  if (del_one_timeout(&(s->timeout), &(s->fds[s->timeout->fd].nb_wait)))
	    continue;
	  return ;
	}
      s->timeout->funct_wait(s, s->timeout->fd, s->timeout);
      if (s->timeout == s->fds[s->timeout->fd].wait)
	s->fds[s->timeout->fd].wait = NULL;
      if (!del_one_timeout(&(s->timeout), &(s->fds[s->timeout->fd].nb_wait)))
	return ;
    }
}

static int	check_max_cmd(t_stck *s, int fd)
{
  if (s->fds[fd].nb_wait > 10)
    return (1);
  s->fds[fd].nb_wait++;
  return (0);
}

int			set_timeout(t_stck *s,
				    int fd,
				    int pause,
				    int (*funct_wait)())
{
  t_wait		*new;
  struct timeval	tp;

  if (check_max_cmd(s, fd))
    return (0);
  new = Xmalloc(sizeof(t_wait));
  if (!s->fds[fd].wait)
    gettimeofday(&tp, NULL);
  else
    {
      tp.tv_sec = (s->fds[fd].wait)->sec;
      tp.tv_usec = (s->fds[fd].wait)->usec;
    }
  new->fd = fd;
  new->sec = tp.tv_sec + (pause / 1000000)
    + ((tp.tv_usec + (pause % 1000000)) / 1000000);
  new->usec = (tp.tv_usec + pause) % 1000000;
  new->funct_wait = funct_wait;
  new->id = s->fds[fd].id;
  if (s->fds[fd].buf_read)
    if (strcmp((new->cmd = strdup(s->fds[fd].buf_read)), "MORT"))
      s->fds[fd].wait = new;
  return ((int)add_in_list(&(s->timeout), new));
}

struct timeval		*check_timeout(t_stck *s, struct timeval *tv, int flag)
{
  struct timeval	tp;
  t_wait		*tmp;

  if (!s->timeout)
    return (NULL);
  tmp = s->timeout;
  memset(tv, 0, sizeof(struct timeval));
  gettimeofday(&tp, NULL);
  while ((tmp->sec - tp.tv_sec == 0 && tmp->usec
	  - tp.tv_usec <= 0) || (tmp->sec - tp.tv_sec < 0))
    {
      flag = 1;
      tmp->use = 1;
      tmp = tmp->next;
      if (!tmp)
	return (tv);
    }
  if (flag)
    return (tv);
  flag = s->timeout->usec - tp.tv_usec < 0 ? 1 : 0;
  tv->tv_sec = s->timeout->sec - tp.tv_sec - flag;
  tv->tv_usec = flag ? 1000000 + (s->timeout->usec - tp.tv_usec)
    : s->timeout->usec - tp.tv_usec;
  return (tv);
}
