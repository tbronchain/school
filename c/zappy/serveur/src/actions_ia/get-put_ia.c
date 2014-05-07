#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/lib.h"
#include "utils/x.h"
#include "actions_ia/get-put_ia.h"

extern t_ressource	gl_res[];

void	get_invent_case(t_stck *s, int fd, char *invent, char *tmp)
{
  int	type;
  int	*val;

  type = -1;
  while (++type  < 6)
    {
      bzero(tmp, 4096);
      val = &(s->fds[fd].invent.linemate) + type;
      if (type != 5)
	sprintf(tmp, "%s %d,", gl_res[(type + 1)].name, *val);
      else
	sprintf(tmp, "%s %d", gl_res[(type + 1)].name, *val);
      strcat(invent, tmp);
    }
  free(tmp);
}

void	update_death_timer(t_stck *s, int fd, int flag)
{
  int	sec;

  sec = (126 * 1000000) / s->t;
  if (flag == 1)
    {
  s->fds[fd].death->sec = s->fds[fd].death->sec + (sec / 1000000)
    + ((s->fds[fd].death->usec + (sec % 1000000)) / 1000000);
  s->fds[fd].death->usec = (s->fds[fd].death->usec + sec) % 1000000;
    }
  else
    {
      s->fds[fd].death->sec = s->fds[fd].death->sec - (sec / 1000000);
      s->fds[fd].death->usec = (s->fds[fd].death->usec + sec) % 1000000;
    }
}

int	get_object_name(char *cmd)
{
  int	len;
  int	flag;

  len = 0;
  flag = 0;
  while (cmd[len])
    {
      while (cmd[len] == ' ')
	{
	  flag = 1;
	  len++;
	}
      if (flag == 1)
	return (len);
      len++;
    }
  return (len);
}
