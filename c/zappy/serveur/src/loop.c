#include <sys/time.h>
#include <sys/timeb.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "colors.h"
#include "loop.h"
#include "ressource.h"
#include "actions_ia/check_action_ia.h"
#include "actions_graph/actions_graph.h"
#include "transfer/funct_write.h"
#include "transfer/send.h"
#include "transfer/recv.h"
#include "utils/kick.h"
#include "utils/timeout.h"
#include "utils/x.h"

static void	init_funct(t_stck *s, int i)
{
  if (s->fds[i].level == END_LEVEL && s->fds[i].type == FD_IA && !s->end)
    {
      FD_SET(i, &(s->fd_w));
      s->end = 1;
      s->win = s->fds[i].team;
    }
  else if (s->fds[i].cbuf_write.len)
    FD_SET(i, &(s->fd_w));
  if (!s->end)
    FD_SET(i, &(s->fd_r));
  s->max_fd = ((s->max_fd > i) ? s->max_fd : i);
}

static int	init_fd(t_stck *s)
{
  char		*tmp;
  int		i;

  i = -1;
  s->max_fd = 0;
  FD_ZERO(&(s->fd_r));
  FD_ZERO(&(s->fd_w));
  while (++i < s->lim_fd)
    if (s->fds[i].err >= MAX_ERR)
      kick(s, i, NULL);
    else if ((s->fds[i]).type != FD_FREE)
      init_funct(s, i);
    else if (i == 0)
      FD_SET(i, &(s->fd_r));
  if (s->end == 1)
    {
      send_all(s, "GAME OVER", FD_CLIENT, FD_IA);
      if (s->win)
	send_graphic((tmp = get_onestr("seg", s->win)), s);
      s->end++;
    }
  return (0);
}

static int	check_end(t_stck *s)
{
  int		flag;
  int		i;

  if (!s->end)
    return (0);
  i = 0;
  flag = 0;
  while (i <= s->max_fd)
    if (s->fds[i++].cbuf_write.len)
      flag++;
    else if (s->fds[i].type == FD_IA)
      kick(s, i, NULL);
  if (!flag)
    {
      printf(REDG"\nTeam %s%s%s%s%s win !\nGame Over%s\n\n",
	     DEFAULT, GREENG, s->win, DEFAULT, REDG, DEFAULT);
      return (1);
    }
  return (0);
}

static int	com_client(t_stck *s, int fd)
{
  if (!fd && FD_ISSET(fd, &(s->fd_r)))
    return (1);
  if (s->fds[fd].fct_write)
    if (FD_ISSET(fd, &(s->fd_w)) && s->fds[fd].type >= FD_CLIENT
	&& s->fds[fd].cbuf_write.len)
      s->fds[fd].fct_write(s, fd);
  if (FD_ISSET(fd, &(s->fd_r)) && s->fds[fd].type >= FD_CLIENT)
    recv_client(s, fd);
  else if (FD_ISSET(fd, &(s->fd_r)) && s->fds[fd].type)
    s->fds[fd].fct_read(s, fd);
  return (0);
}

int			loop(t_stck *s)
{
  static int		stop = 0;
  struct timeval	tv;
  int			i;

  while (1)
    {
      i = init_fd(s);
      if (_X((void *)-1, (void *)select(s->max_fd + 1, &(s->fd_r), &(s->fd_w),
					NULL, check_timeout(s, &tv, 0)),
	     "select") == (void *)-1)
	{
	  if (stop++ < MAX_ERR)
	    continue;
	  exit(EXIT_FAILURE);
	}
      stop = 0;
      if (check_end(s))
	break;
      exec_timeout(s);
      while (i <= s->max_fd)
	if (com_client(s, i++))
	  return (0);
      check_ressource(s);
    }
  return (0);
}
