#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "client/gtk.h"
#include "client/client.h"
#include "client/cmd_client.h"
#include "client/init_client.h"
#include "client/x.h"

static int	extract_port(char *cmd, int i)
{
  char		*tmp;
  int		port;
  int		k;

  k = 0;
  tmp = Xmalloc(strlen(cmd) + 1);
  while (cmd[i])
    tmp[k++] = cmd[i++];
  tmp[k] = '\0';
  if (k == 0)
    port = -1;
  else
    port = atoi(tmp);
  free(tmp);
  return (port);
}

static char	*extract_host_port(t_main *c)
{
  char		*host;
  int		i;

  i = 0;
  if (!c->tab[1])
    return (NULL);
  host = Xmalloc(strlen(c->tab[1]) + 1);
  while (c->tab[1][i] != ':' && c->tab[1][i])
    {
      host[i] = c->tab[1][i];
      i++;
    }
  host[i] = '\0';
  if (!i)
    {
      free(host);
      return (NULL);
    }
  c->port = extract_port(c->tab[1], i + 1);
  return (host);
}

static int	check_info_connex(t_main *c)
{
  int		i;

  i = 0;
  while (c->tab[i])
    i++;
  if (!c->host || i > 2)
    {
      aff_msg(c->m, "Usage: /server _host_[:port]\n");
      return (-1);
    }
  if (c->port < -1 || c->port > 65535)
    {
      aff_msg(c->m, "Usage: /server _host_[:65535 > port > 0]\n");
      return (-1);
    }
  return (0);
}

void	connect_to_serv(t_main *c)
{
  char	*tmp;

  c->host = extract_host_port(c);
  if (check_info_connex(c) == -1)
    {
      free(c->host);
      return ;
    }
  if (!strcmp("localhost", c->host))
    c->sfd = init_client(c, "127.0.0.1", c->port);
  else
    c->sfd = init_client(c, c->host, c->port);
  if (c->sfd == -1)
    return ;
  tmp = Xmalloc(strlen(c->host) + 40);
  sprintf(tmp, "Connected to '%s'\n", c->host);
  aff_msg(c->m, tmp);
  free(tmp);
  free(c->host);
  c->connect = TRUE;
}
