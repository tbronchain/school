#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
#include "parse_opt.h"
#include "utils/check_team.h"
#include "utils/lib.h"
#include "utils/x.h"

t_opt      gl_opt[] =
  {
    {'p', save_opt},
    {'x', save_map_opt},
    {'y', save_map_opt},
    {'c', save_opt},
    {'t', save_opt},
    {0, 0}
  };

char	*save_map_opt(t_stck *s, int *nb_opt, int opt_char, int *default_opt)
{
  (void)nb_opt;
  (*default_opt)++;
  if (opt_char == 'x')
    {
      if (atoi(s->win) > 0 && atoi(s->win) <= MAX_X)
	s->map.x = atoi(s->win);
      else
	{
	  s->map.x = 20;
	  return (ERR_MAP_X);
	}
    }
  else if (opt_char == 'y')
    {
      if (atoi(s->win) > 0 && atoi(s->win) <= MAX_Y)
	s->map.y = atoi(s->win);
      else
	{
	  s->map.y = 20;
	  return (ERR_MAP_Y);
	}
    }
  return (NULL);
}

char	*save_opt(t_stck *s, int *nb_opt, int opt_char, int *default_opt)
{
  if (opt_char == 'c')
    {
      (*default_opt)++;
      if (atoi(s->win) > 0 && atoi(s->win) < s->lim_fd)
	s->max_tclient = atoi(s->win);
      else
	return (ERR_NB_CLIENT);
    }
  else if (opt_char == 't')
    {
      (*default_opt)++;
      if (atoi(s->win) > 0 && atoi(s->win) < 1000000)
	s->t = atoi(s->win);
      else
	s->t = 100;
    }
  else
    {
      (*nb_opt)++;
      if (atoi(s->win) > 0 && atoi(s->win) < MAX_PORT)
	s->port = atoi(s->win);
      else
	return (ERR_PORT);
    }
  return (NULL);
}

int	get_default_value(t_stck *s, int nb_opt)
{
  if (nb_opt == OPT_NB)
    {
      s->map.x = s->map.x > 0 ? s->map.x : DEFAULT_X;
      s->map.y = s->map.y > 0 ? s->map.y : DEFAULT_Y;
      s->t = s->t > 0 ? s->t : DEFAULT_TIME;
      s->max_tclient = s->max_tclient > 0 ? s->max_tclient : DEFAULT_NB_CLIENT;
      return (0);
    }
  else
    return (-1);
}

int	get_option(t_stck *s, char **av, t_parse *p)
{
  char	*error;

  if (av[p->i + 1])
    s->win = av[p->i + 1];
  if ((error = gl_opt[p->j].f(s,
			      &(p->nb_option),
			      av[p->i][1],
			      &(p->default_opt))))
    {
      fprintf(stderr, "error : %s\n", error);
      return (-1);
    }
  return (0);
}

int		parse_opt(t_stck *s, int ac, char **av)
{
  t_parse	p;

  p.i = 1;
  p.nb_option = 0;
  p.default_opt = 0;
  while (p.i < (ac - 1))
    {
      p.j = -1;
      while (gl_opt[++p.j].opt)
	if (av[p.i][0] != '\0' && av[p.i][0] == '-'
	    && gl_opt[p.j].opt == av[p.i][1])
	  if (get_option(s, av, &p) == -1)
	    return (-1);
      p.i++;
    }
  s->win = NULL;
  if (p.nb_option == OPT_NB && p.default_opt == DEFAULT_OPT_NB)
    return (get_teams(s, ac, av));
  else
    get_teams(s, ac, av);
  return (get_default_value(s, p.nb_option));
}
