#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "wolf3d.h"

void	x_malloc(char *str, int size)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      my_put_error(ERR_MALLOC);
      exit(EXIT_FAILURE);
    }
  while (i != size)
    str[i++] = 0;
}

void	x_malloc_2d(char **tab, int size)
{
  int	i;

  i = 0;
  if (tab == NULL)
    {
      my_put_error(ERR_MALLOC);
      exit(EXIT_FAILURE);
    }
  while (i != size)
    tab[i++] = NULL;
}
