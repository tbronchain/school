#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void	win_exit(t_lx *mlx)
{
  my_putstr("YOU WIN !!\n");
  free_struct(mlx);
  exit(EXIT_SUCCESS);
}

void	aff_map(t_lx *mlx)
{
  int	i;
  int	j;

  j = 0;
  while (j < 40)
    {
      i = 0;
      while (i < 40)
	{
	  my_put_nbr(mlx->map[j][i]);
	  i++;
	}
      my_putchar('\n');
      j++;
    }
}

void	init_tab(t_lx *mlx)
{
  mlx->ang = 0;
  mlx->map = malloc(40 * sizeof(*(mlx->map)));
  x_malloc_2d(mlx->map, 40);
  mlx->map = my_tab_malloc(mlx->map, 40, 40);
  x_malloc(mlx->or, 8);
  set_map(mlx);
  mlx->or[NO] = 0;
  mlx->or[NE] = 0;
  mlx->or[EA] = 1;
  mlx->or[SE] = 0;
  mlx->or[SO] = 0;
  mlx->or[SW] = 0;
  mlx->or[WE] = 0;
  mlx->or[NW] = 0;
}

void	event(t_lx *mlx)
{
  mlx_key_hook(mlx->win_ptr, gere_key, mlx);
  mlx_loop(mlx->mlx_ptr);
}

int	main()
{
  t_lx 	mlx;

  init_tab(&mlx);
  init(&mlx);
  aff_map(&mlx);
  mlx_expose_hook(mlx.win_ptr, gere_expose_img, &mlx);
  event(&mlx);
  return (0);
}
