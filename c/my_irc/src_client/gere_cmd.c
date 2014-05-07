#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "client/gtk.h"
#include "client/client.h"
#include "client/cmd_client.h"
#include "client/utils.h"

static int	check_cmd(char **tab)
{
  if (!tab[0])
    return (-1);
  else if (!strlen(tab[0]))
    return (-1);
  return (0);
}

int		gere_cmd(t_main *c)
{
  if (check_cmd(c->tab))
    return (1);
  if (c->connect == FALSE && !strcmp("/server", c->tab[0]))
    {
      connect_to_serv(c);
      return (1);
    }
  else if (c->connect == TRUE && !strcmp("/disconnect", c->tab[0]))
    {
      disconnect(c);
      return (1);
    }
  else if (c->connect == FALSE)
    return (-1);
  return (0);
}
