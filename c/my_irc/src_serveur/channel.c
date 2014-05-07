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
#include "serveur/list.h"
#include "serveur/x.h"

static int	add_channel(t_stck *s, char *name)
{
  t_chan	*new;
  t_chan	*tmp;

  if (!null(name))
    return (-1);
  else if (strlen(name) > CHAN_LEN)
    return (-1);
  tmp = s->channel;
  while (tmp)
    {
      if (!strcmp(tmp->name, name))
	return (0);
      tmp = tmp->next;
    }
  new = Xmalloc(sizeof(t_chan));
  new->next = NULL;
  new->prev = NULL;
  strcpy(new->name, name);
  if (!(s->channel))
    s->channel = new;
  else
    add_sorted(&(s->channel), new, s->channel);
  return (1);
}

static int	check_nickname(t_stck *s, int fd, char *channel)
{
  int		i;
  int		len;

  i = 0;
  srand(time(NULL));
  while (i < (s->max_fd + 1))
    {
      if (s->fds[i].type == FD_CLIENT &&
	  !strcmp(s->fds[i].nickname, s->fds[fd].nickname) &&
	  !strcmp(s->fds[i].channel, channel) && i != fd)
	{
	  i = 0;
	  if ((len = strlen(s->fds[fd].nickname)) >= (NICK_LEN + 10))
	    {
	      send_msg("Too much users.", fd, SERVER_NAME);
	      return (-1);
	    }
	  (s->fds[fd].nickname)[len] = RANDOM('0', '9');
	}
      i++;
    }
  return (0);
}

int	join(t_stck *s, int fd, char **cmd)
{
  char	*tmp;

  if (add_channel(s, cmd[1]) == -1)
    {
      send_msg("Wrong channel name.", fd, SERVER_NAME);
      return (-1);
    }
  if (check_nickname(s, fd, cmd[1]))
    return (-1);
  if (s->fds[fd].channel[0])
    {
      tmp = my_strcat(s->fds[fd].nickname, " has left the channel.");
      send_oth(s, fd, tmp, s->fds[fd].channel, SERVER_NAME);
      free(tmp);
    }
  strcpy(s->fds[fd].channel, cmd[1]);
  tmp = my_strcat("Joined channel: ", cmd[1]);
  send_msg(tmp, fd, SERVER_NAME);
  free(tmp);
  tmp = my_strcat(s->fds[fd].nickname, " has joined the channel.");
  send_oth(s, fd, tmp, cmd[1], SERVER_NAME);
  free(tmp);
  return (1);
}

int		list(t_stck *s, int fd, char **cmd)
{
  t_chan	*tmp;
  int		j;

  j = 0;
  tmp = s->channel;
  if (!cmd[1])
    while (tmp)
      {
	send_msg(tmp->name, fd, NULL);
	tmp = tmp->next;
      }
  else
    while (tmp)
      {
	if (strstr(tmp->name, cmd[1]))
	  send_msg(tmp->name, fd, NULL);
	tmp = tmp->next;
      }
  return (1);
}
