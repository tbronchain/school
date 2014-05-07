#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "wolf3d.h"

void	make_right_rotate(t_lx *mlx)
{
  my_putstr("RIGHT\n");
  mlx->ang -= (PI/4);
  aff_first_ok_img(mlx);
}

void	make_left_rotate(t_lx *mlx)
{
  my_putstr("LEFT\n");
  mlx->ang += (PI/4);
  aff_first_ok_img(mlx);
}
