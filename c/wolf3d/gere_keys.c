#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void	next(t_lx *mlx)
{
  mlx->old_x = mlx->x;
  mlx->old_y = mlx->y;
  if (mlx->key_u == 1)
    {
      make_ku(mlx);
      if (mlx->x != mlx->old_x || mlx->y != mlx->old_y)
	make_move_up(mlx);
    }
  else if (mlx->key_d == 1)
    {
      make_kd(mlx);
      if (mlx->x != mlx->old_x || mlx->y != mlx->old_y)
	make_move_down(mlx);
    }
  else if (mlx->key_l == 1)
    make_kl(mlx);
  else if (mlx->key_r == 1)
    make_kr(mlx);
}

int	gere_key(int keycode, t_lx *mlx)
{
  mlx->key_l = 0;
  mlx->key_u = 0;
  mlx->key_r = 0;
  mlx->key_d = 0;
  if (keycode == 65307)
    {
      free_struct(mlx);
      exit(EXIT_SUCCESS);
    }
  else if (keycode == 65361)
    mlx->key_l = 1;
  else if (keycode == 65362)
    mlx->key_u = 1;
  else if (keycode == 65363)
    mlx->key_r = 1;
  else if (keycode == 65364)
    mlx->key_d = 1;
  next(mlx);
  return (0);
}
