#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "parse_opt.h"
#include "utils/check_team.h"
#include "utils/x.h"
#include "utils/lib.h"
#include "utils/free.h"

int		get_team_c(t_teams *list, char *team)
{
  t_teams	*tmp;

  tmp = list;
  while (tmp)
    {
      if (!strcmp(tmp->team, team))
	return (tmp->c);
      tmp = tmp->next;
    }
  return (0);
}

void		mod_team_c(t_teams *list, char *team, int flag)
{
  t_teams	*tmp;

  tmp = list;
  while (tmp)
    {
      if (!strcmp(tmp->team, team))
	{
	  tmp->c += flag;
	  return ;
	}
      tmp = tmp->next;
    }
}

char	*check_team_names(t_stck *s, char *team)
{
  int	j;

  j = 0;
  while (s->teams[j])
    {
      if (!strcmp(s->teams[j], team))
	return (s->teams[j]);
      j++;
    }
  return (NULL);
}

int	get_teams(t_stck *s, int ac, char **av)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  tmp = Xmalloc(4096 * sizeof(tmp));
  while (i < (ac - 1) && strcmp(av[i], "-n") != 0)
    i++;
  i++;
  j = i;
  while (j < ac && av[j][0] != '-')
    j++;
  while (i < j)
    {
      if (av[i][0] == '\0' || strcmp("GRAPHIC", av[i]) == 0
	  || strlen(av[i]) > TEAM_LEN)
	{
	  fprintf(stderr, "error : %s\n", ERR_GRAPHIC);
	  return (-1);
	}
      strcat(tmp, av[i++]);
      strcat(tmp, " ");
    }
  s->teams = str_to_wordtab(tmp, ' ');
  return ((int)xfree(tmp));
}

int	check_team_nb(t_stck *s, int fd, char *team)
{
  int	i;
  int	nb;

  (void)fd;
  i = 0;
  nb = 0;
  while (i <= s->max_fd)
    {
      if (s->fds[i].team)
	if (!strcmp(s->fds[i].team, team))
	  nb++;
      i++;
    }
  return (nb);
}
