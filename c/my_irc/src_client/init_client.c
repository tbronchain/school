#include <sys/select.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <gtk/gtk.h>
#include "client/gtk.h"
#include "client/client.h"
#include "client/init_client.h"
#include "client/x.h"

int			init_client(t_main *c, char *machine, int port)
{
  struct protoent	*p;
  struct sockaddr_in    s;
  int			sockfd;
  int			num_proto;

  p = getprotobyname("tcp");
  if (p == NULL)
    num_proto = 0;
  else
    num_proto = p->p_proto;
  sockfd = (int)X((void *)-1,
		  (void *)socket(PF_INET, SOCK_STREAM, num_proto), "socket");
  if (port == -1)
    port = DEFAULT_PORT;
  s.sin_family = AF_INET;
  s.sin_addr.s_addr = inet_addr(machine);
  s.sin_port = htons(port);
  if (connect(sockfd, (struct sockaddr *)&s, sizeof(s)) == -1)
    {
      aff_msg(c->m, "Error: unable to connect.\n");
      return (-1);
    }
  return (sockfd);
}
