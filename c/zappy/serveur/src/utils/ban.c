#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "colors.h"
#include "utils/ban.h"
#include "utils/x.h"

int			check_ban(t_ban **ban, char *ip, int fd)
{
  struct in_addr	*addr;
  t_ban			*tmp;

  tmp = *ban;
  while (tmp)
    {
      if (!memcmp(ip, tmp->ip, sizeof(struct in_addr)))
	{
	  _X((void *)-1, (void *)close(fd), "close");
	  addr = (struct in_addr *)ip;
	  printf(REDG"\nClient #%d used banned ip address: %s,"	\
		 " connexion refused%s\n\n", fd, inet_ntoa(*addr), DEFAULT);
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

void			ban(t_ban **ban, char *ip, int fd)
{
  struct in_addr	*addr;
  t_ban			*new;

  new = Xmalloc(sizeof(*new));
  new->ip = Xmalloc(sizeof(struct in_addr));
  memcpy(new->ip, ip, sizeof(struct in_addr));
  new->next = *ban;
  *ban = new;
  addr = (struct in_addr *)ip;
  printf(REDG"\nClient #%d BANNED, ip banned: %s%s\n\n",
	 fd, inet_ntoa(*addr), DEFAULT);
}
