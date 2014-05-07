#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "client/gtk.h"
#include "client/client.h"
#include "client/x.h"

void	disconnect(t_main *c)
{
  _X((void *)-1, (void *)close(c->sfd), "close");
  c->connect = FALSE;
  aff_msg(c->m, "Goodbye !\n");
}
