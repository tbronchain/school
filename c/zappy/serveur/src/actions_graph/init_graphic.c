#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/x.h"
#include "transfer/send.h"
#include "utils/kick.h"
#include "actions_graph/init_graphic.h"
#include "actions_graph/actions_graph.h"

static void	send_players(t_stck *s, int fd)
{
  t_gparam	res;
  char		*tmp;
  int		i;

  i = 0;
  while (i <= s->max_fd)
    {
      if (s->fds[i].type == FD_IA)
	{
	  res.n = i;
	  send_one((tmp = get_pnw(s, &res)), fd, s);
	  free(tmp);
	}
      i++;
    }
}

static void	send_eggs(t_stck *s, int fd)
{
  t_egg		*cur;
  t_gparam	res;
  char		*tmp;

  cur = s->egg;
  while (cur)
    {
      res.e = cur->id;
      res.e = cur->x;
      res.e = cur->y;
      send_one((tmp = get_enw(s, &res)), fd, s);
      free(tmp);
      cur = cur->next;
    }
}

void		init_graphic(t_stck *s, int fd)
{
  t_gparam	res;
  char		*tmp;

  memset(&res, 0, sizeof(res));
  send_one((tmp = get_msz(s, NULL)), fd, s);
  free(tmp);
  send_one((tmp = get_sgt(s, NULL)), fd, s);
  free(tmp);
  res.fd = fd;
  get_mct(s, &res);
  get_tna(s, &res);
  send_players(s, fd);
  send_eggs(s, fd);
}
