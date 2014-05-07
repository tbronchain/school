#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur/serveur.h"
#include "serveur/cmd_serv.h"
#include "serveur/init.h"
#include "serveur/client_read.h"
#include "serveur/lib.h"
#include "serveur/x.h"

int	send_msg(char *msg, int fd, char *nick)
{
  char	*tmp;
  int	res;
  int	len;

  len = strlen(msg) + 10;
  if (nick)
    len += strlen(nick);
  tmp = Xmalloc(len);
  if (nick)
    {
      strcpy(tmp, nick);
      strcat(tmp, ": ");
      strcat(tmp, msg);
    }
  else
    strcpy(tmp, msg);
  strcat(tmp, "\n\r");
  if ((res = send(fd, tmp, strlen(tmp), 0)) == -1)
    fprintf(stderr, "Error while sending %s to %d\n", msg, fd);
  free(tmp);
  return (res);
}

void	send_all(t_stck *s, char *msg, char *chan, char *nick)
{
  int	i;

  i = 0;
  if (!chan || !msg)
    return ;
  else if (!strlen(chan) || !strlen(msg))
    return ;
  while (i < s->lim_fd)
    {
      if ((s->fds[i]).type == FD_CLIENT &&
	  !strcmp((s->fds[i]).channel, chan))
	send_msg(msg, i, nick);
      i++;
    }
}

void	send_oth(t_stck *s, int fd, char *msg, char *chan, char *nick)
{
  int	i;

  i = 0;
  if (!chan || !msg)
    return ;
  else if (!strlen(chan) || !strlen(msg))
    return ;
  while (i < s->lim_fd)
    {
      if ((s->fds[i]).type == FD_CLIENT &&
	  !strcmp((s->fds[i]).channel, chan) && i != fd)
	send_msg(msg, i, nick);
      i++;
    }
}
