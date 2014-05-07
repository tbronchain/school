#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <gtk/gtk.h>
#include "client/gtk.h"
#include "client/client.h"
#include "client/com_serv.h"
#include "client/cmd_client.h"
#include "client/gere_cmd.h"
#include "client/utils.h"
#include "client/str_to_wordtab.h"
#include "client/x.h"

static void		do_select(t_main *c)
{
  struct timeval	tv;
  int			queue;

  FD_ZERO(&(c->fd_read));
  FD_SET(c->sfd, &(c->fd_read));
  tv.tv_sec = 0;
  tv.tv_usec = 1000;
  queue = (int)X((void *)-1, (void *)select
		 (c->sfd + 1, &(c->fd_read),
		  NULL, NULL, &tv), "select");
  if (FD_ISSET(c->sfd, &(c->fd_read)) && queue > 0)
    recv_serv(c);
}

int		main(int ac, char **av)
{
  t_main	c;
  int		res;

  c.connect = FALSE;
  c.m = init_gtk(&ac, &av);
  c.start = 0;
  c.end = 0;
  while (1)
    {
      if (c.connect == TRUE)
	do_select(&c);
      gtk_main_iteration();
      if (!c.m->buffer)
	continue;
      c.tab = str_to_wordtab((char *)c.m->buffer);
      if ((res = gere_cmd(&c)) == -1)
	aff_msg(c.m, "Usage: /server host[:port]\n");
      else if (!res)
	send_serv(c.m, c.m->buffer, c.sfd);
      gtk_widget_show_all(c.m->main_win);
      free_tab(c.tab);
      c.m->buffer = xfree(c.m->buffer);
    }
  return (EXIT_SUCCESS);
}
