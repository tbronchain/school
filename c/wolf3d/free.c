#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void	free_tab(char **tab)
{
  int	size;
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      size = my_strlen(tab[i]);
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	free_struct(t_lx *mlx)
{
  free_tab(mlx->map);
}
