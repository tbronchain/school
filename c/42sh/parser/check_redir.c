#include <stdlib.h>
#include <string.h>
#include "count_fcts.h"
#include "modif_str_fcts.h"
#include "error.h"
#include "token.h"
#include "check_redir.h"
#include "x_function.h"

static void	from_str(char **command, char *tmp)
{
  int		len;
  int		i;
  char		*str;

  len = my_strlen(tmp);
  str = *command;
  while (*str && strncmp(tmp, str, len))
    str++;
  if (!(*str))
    return ;
  i = 0;
  while (str[i + len])
    {
      str[i] = str[i + len];
      i++;
    }
  str[i] = 0;
}

static char	*name_clear(char *str)
{
  while (*str == token_val(" "))
    str++;
  return (my_strdup(str));
}

static char	*check_redir(char *str, char cut)
{
  char		*new;
  int		i;
  int		j;

  while (*str && *str != cut)
    str++;
  new = my_strdup(str);
  i = 1;
  while (str[i] == token_val(" "))
    i++;
  j = i;
  while (str[i] && str[i] > 0)
    i++;
  if (i == j)
    {
      my_put_error(ERR_NAME_REDIR, 0);
      return (0);
    }
  new[i] = 0;
  new = xrealloc(new, (my_strlen(new) + 1) * sizeof(*new));
  return (new);
}

char	*go_after(char **command, char cut)
{
  char	*str;
  char	*ret;
  char	*tmp;

  str = *command;
  tmp = str;
  while (*str && *str != cut)
    str++;
  if (!(*str))
    return (0);
  str = tmp;
  if (!(tmp = check_redir(str, cut)))
    return ((char *) - 1);
  from_str(command, tmp);
  ret = name_clear(tmp + 1);
  free(tmp);
  return (ret);
}
