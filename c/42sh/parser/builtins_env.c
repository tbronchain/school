#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "builtins_env.h"
#include "count_fcts.h"
#include "display_fcts.h"
#include "list_for_env.h"
#include "modif_str_fcts.h"
#include "xfunction_termcap_next.h"
#include "x_function.h"
#include "free_list.h"
#include "error.h"
#include "utils.h"

int     test_ever_in_env(char **arg)
{
  int   nb;

  arg[1][my_strlen(arg[1])] = '=';
  nb = find_in_list_env(my_env.begin, arg[1]);
  if (nb != -1)
    my_put_error("setenv: sorry, ever in environnement.\n", 0);
  return (0);
}

int	built_env(void)
{
  int	i;

  i = 0;
  while (my_env.my_environ[i] != NULL)
    i++;
  i--;
  while (i >= 0)
    {
      my_putstr(my_env.my_environ[i--]);
      my_putchar('\n');
    }
  return (1);
}

int	built_unsetenv(char **arg)
{
  int	nb;

  if (arg[2] != NULL || arg[1] == NULL)
    {
      my_put_error("unsetenv: bad number of arguments\n", 0);
      return (0);
    }
  arg[1][my_strlen(arg[1])] = '=';
  nb = find_in_list_env(my_env.begin, arg[1]);
  if (nb == -1)
    my_put_error("unsetenv: variable not found\n", 0);
  if (nb == -1)
    return (0);
  if (del_elems(&(my_env.begin), my_env.my_environ[nb]) == -1)
    return (0);
  free_tab(my_env.my_environ);
  my_env.my_environ = xmalloc_2d(my_env.my_environ, my_env.size + 2);
  my_put_in_tab(my_env.begin, my_env.my_environ);
  return (1);
}

int     built_setenv(char **arg)
{
  char  *data;

  if (my_tab_len(arg) != 3)
    {
      my_put_error("setenv: Bad number of arguments.\n", 0);
      return (0);
    }
  if (test_ever_in_env(arg) == -1)
    return (0);
  data = xmalloc(my_strlen(arg[1]) * sizeof(**arg));
  data = strcpy(data, arg[1]);
  data[my_strlen(arg[1]) + my_strlen(arg[2]) + 1] = '\0';
  my_put_in_list(&(my_env.begin), data);
  free_tab(my_env.my_environ);
  my_env.my_environ = xmalloc_2d(my_env.my_environ, (my_env.size + 2));
  my_put_in_tab(my_env.begin, my_env.my_environ);
  return (0);
}

