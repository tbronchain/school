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

int	quit(t_stck *s, int fd, char **cmd)
{
  char	*tmp;

  (void)cmd;
  _X((void *)-1, (void *)close(fd), "close");
  if (s->fds[fd].channel[0])
    {
      tmp = my_strcat(s->fds[fd].nickname, " has left the channel.");
      send_oth(s, fd, tmp, s->fds[fd].channel, SERVER_NAME);
      free(tmp);
    }
  memset(&(s->fds[fd]), 0, sizeof(t_fd));
  printf("client #%d gone away\n", fd);
  return (1);
}

int	me(t_stck *s, int fd, char **cmd)
{
  (void)cmd;
  send_msg(s->fds[fd].nickname, fd, NULL);
  return (1);
}
