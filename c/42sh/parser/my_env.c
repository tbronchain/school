#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "error.h"
#include "count_fcts.h"
#include "utils.h"
#include "modif_str_fcts.h"
#include "my_env.h"

static int	my_cmp_env(char *env, char *str)
{
  int	i;

  i = 0;
  while (env[i] == str[i])
    i++;
  if (env[i] == '=' && str[i] == '\0')
    return (0);
  return (-1);
}

char		*my_getenv(char *str)
{
  int		i;
  int		y;
  char		*copy;
  extern char	**environ;

  i = 0;
  copy = NULL;
  while (environ[i] != NULL)
    {
      if (my_cmp_env(environ[i], str) == 0)
        {
          y = 0;
	  while (environ[i][y] != '=')
	    y++;
	  y++;
	  copy = my_xmalloc(copy, y);
	  copy = my_nstrcpy(copy, environ[i], y);
	}
      i++;
    }
  return (copy);
}
