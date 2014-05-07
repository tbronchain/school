#include <stdlib.h>
#include "struct.h"
#include "count_fcts.h"
#include "list_for_env.h"
#include "init_env.h"
#include "display_fcts.h"
#include "modif_str_fcts.h"
#include "xfunction_termcap_next.h"
#include "error.h"

int	find_in_env(char **tab, char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tab[j] != NULL && str[i] != '\0')
    {
      while (tab[j][i] != str[i] && str[i] != '\0' && tab[j][i] != \
             '\0')
        {
          i = 0;
          j++;
          if (tab[j] == NULL)
            return (-1);
        }
      if (tab[j][i] == str[i])
        i++;
    }
  if (i == 0)
    return (-1);
  return (j);
}

char	*cpy_pwd_env (char *pwd, int size)
{
  int	where;

  where = find_in_env(my_env.my_environ, "PWD=/");
  pwd = x_malloc(my_env.pwd, my_strlen(my_env.my_environ[where])
		 + size);
  my_strdcpy(pwd, my_env.my_environ[where], 4);
  return (pwd);
}

void	make_path(char **my_env, char **path, int where, int size)
{
  int	i;
  int	j;
  int	k;

  i = 5;
  j = 0;
  k = 0;
  if (my_env[where] != NULL)
    {
      path[j] = x_malloc(path[j], size);
      while (my_env[where][i] != '\0')
        if (my_env[where][i] != ':')
          path[j][k++] = my_env[where][i++];
        else if (my_env[where][i] == ':')
          {
            j++;
            path[j] = x_malloc(path[j], size);
            k = 0;
            i++;
          }
    }
}

int     test_env(char **environ)
{
  if (find_in_env(environ, "PWD=/") == -1)
    return (-1);
  if (find_in_env(environ, "USER=") == -1)
    return (-1);
  if (find_in_env(environ, "HOME=/") == -1)
    return (-1);
  if (find_in_env(environ, "PATH=/") == -1)
    return (-1);
  if (find_in_env(environ, "USERNAME=") == -1)
    if (find_in_env(environ, "USER=") == -1)
      return (-1);
  return (0);
}

int		init_env()
{
  extern char	**environ;
  int		where;
  int		size;

  my_env.begin = NULL;
  if (test_env(environ) != -1)
    if ((my_env.size = my_tab_len(environ)) != 0 && environ[0][0] != '\0')
      {
        my_env.my_environ = xmalloc_2d(my_env.my_environ, my_env.size + 2);
        my_list_tab_cpy(environ, &my_env.begin);
        my_put_in_tab(my_env.begin, my_env.my_environ);
        where = find_in_env(my_env.my_environ, "PATH=");
        size = my_strlen(my_env.my_environ[where]) + 1;
        my_env.path = xmalloc_2d(my_env.path, size);
        make_path(my_env.my_environ, my_env.path, where, size);
        my_env.pwd = cpy_pwd_env(my_env.pwd, 0);
        return (0);
      }
  my_put_error("Environement error, please check your configuration.\n", 1);
  return (0);
}
