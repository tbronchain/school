#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include "my_select.h"

char	*make_str(char *found, char *src)
{
  int	size;
  int	i;
  int	j;

  i = 0;
  j = 0;
  size = my_strlen(src);
  found = malloc(size * sizeof(*found));
  x_malloc(found, size);
  while (src[i++] != '=');
  while (src[i] != '\0')
    found[j++] = src[i++];
  return (found);
}

char	*cpy_from_env(char **tab, char *str)
{
  char	*found;
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tab[j] != NULL && str[i] != '\0')
    {
      while (tab[j][i] != str[i] && str[i] != '\0' && tab[j][i] != '\0')
        {
          i = 0;
          j++;
          if (tab[j] == NULL)
            return (NULL);
        }
      if (tab[j][i] == str[i])
        i++;
    }
  if (i == 0)
    return (NULL);
  found = make_str(found, tab[j]);
  return (found);
}
