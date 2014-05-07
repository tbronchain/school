#include <sys/select.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "serveur/serveur.h"
#include "serveur/cmd_serv.h"
#include "serveur/channel.h"
#include "serveur/send.h"
#include "serveur/lib.h"
#include "serveur/x.h"
#include "serveur/free.h"

static int	change_nick(t_stck *s, int fd, char *old, char *new)
{
  char		*tmp;
  char		*res;
  int		i;

  i = -1;
  if (!(s->fds[fd].channel[0]))
    return (0);
  while (++i < s->lim_fd)
    if (s->fds[i].type == FD_CLIENT &&
	!strcmp(s->fds[i].nickname, new) &&
	!strcmp(s->fds[i].channel, s->fds[fd].channel))
      {
	send_msg("Nickname already used.", fd, SERVER_NAME);
	return (-1);
      }
  tmp = my_strcat(old, " changed his nickname to ");
  res = my_strcat(tmp, new);
  free(tmp);
  send_all(s, res, s->fds[fd].channel, SERVER_NAME);
  free(res);
  return (0);
}

int	nick(t_stck *s, int fd, char **cmd)
{
  if (!null(cmd[1]))
    {
      send_msg("Wrong nickname.", fd, SERVER_NAME);
      return (-1);
    }
  else if (!strcmp(cmd[1], SERVER_NAME))
    {
      send_msg("Wrong nickname.", fd, SERVER_NAME);
      return (-1);
    }
  else if (change_nick(s, fd, s->fds[fd].nickname, cmd[1]) == -1)
    return (-1);
  strncpy(s->fds[fd].nickname, cmd[1], NICK_LEN);
  return (1);
}

int	users(t_stck *s, int fd, char **cmd)
{
  char	**tab;
  int	i;
  int	j;

  (void)cmd;
  i = -1;
  j = 0;
  if (!s->fds[fd].channel[0])
    return (-1);
  tab = Xmalloc(s->lim_fd * sizeof(char *));
  while (++i < (s->max_fd + 1))
    if (s->fds[i].type == FD_CLIENT &&
	!strcmp(s->fds[i].channel, s->fds[fd].channel))
      {
	tab[j] = Xmalloc(NICK_LEN + 1);
	strcpy(tab[j++], s->fds[i].nickname);
      }
  sort_tab(tab);
  i = 0;
  while (i < j)
    send_msg(tab[i++], fd, NULL);
  free_tab(tab);
  return (1);
}

int	msg(t_stck *s, int fd, char **cmd)
{
  char	*res;
  char	*str;
  int	i;

  i = -1;
  if (!cmd[1])
    return (-1);
  else if (!cmd[2])
    return (-1);
  if (!s->fds[fd].channel[0])
    return (-1);
  while (++i < s->lim_fd)
    if (s->fds[i].type == FD_CLIENT &&
	!strcmp(s->fds[i].channel, s->fds[fd].channel) &&
	!strcmp(s->fds[i].nickname, cmd[1]))
      {
	str = concat(cmd, 2);
	send_msg(str, i, (res = my_strcat("PV:", s->fds[fd].nickname)));
	free(res);
	send_msg(str, fd, (res = my_strcat("PV:", s->fds[fd].nickname)));
	free(res);
	free(str);
      }
  return (1);
}

int	part(t_stck *s, int fd, char **cmd)
{
  char	*channel;
  char	*tmp;

  (void)cmd;
  channel = s->fds[fd].channel;
  if (!channel[0])
    return (-1);
  tmp = my_strcat("Leaving channel: ", channel);
  send_msg(tmp, fd, SERVER_NAME);
  free(tmp);
  tmp = my_strcat(s->fds[fd].nickname, " has left the channel.");
  send_oth(s, fd, tmp, channel, SERVER_NAME);
  free(tmp);
  channel[0] = '\0';
  return (1);
}
