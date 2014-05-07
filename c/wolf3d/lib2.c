#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "wolf3d.h"

char	**my_tab_malloc(char **tab, int size1, int size2)
{
  int	i;

  i = 0;
  while (i != size1)
    {
      tab[i] = malloc(size2 * sizeof(*tab));
      x_malloc(tab[i++], size2);
    }
  return (tab);
}
