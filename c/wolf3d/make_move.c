#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void	make_move_up(t_lx *mlx)
{
  my_putstr("UP\n");
  aff_first_ok_img(mlx);
}

void	make_move_down(t_lx *mlx)
{
  my_putstr("DOWN\n");
  aff_first_ok_img(mlx);
}
