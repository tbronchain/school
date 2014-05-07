#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void	init_plan(t_lx *mlx)
{
  float	x;

  x = 0;
  while (x < WIDTH)
    {
      mlx->x1[(int)x] = 0.5;
      mlx->y1[(int)x] = ((WIDTH/ 2) - x) / WIDTH;
      x++;
    }
}

int	gere_expose_img(t_lx *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
  return (0);
}

void	aff_first_img(t_lx *mlx)
{
  int	i;

  i = 0;
  while (i != 960000)
    {
      if (i <= 480000)
	mlx->data[i] = mlx->sky_cl;
      else
	mlx->data[i] = mlx->floor_cl;
      i++;
    }
}

void	init(t_lx *mlx)
{
  mlx->mlx_ptr = mlx_init();
  mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
  mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Wolf3D");
  mlx->data = (unsigned char *)mlx_get_data_addr
    (mlx->img_ptr, &(mlx->bpp), &(mlx->sizeline), &(mlx->endian));
  mlx->floor_cl = 110;
  mlx->sky_cl = 60;
  mlx->n_cl = 40;
  mlx->s_cl = 200;
  mlx->e_cl = 100;
  mlx->w_cl = 240;
  mlx->ang = 0;
  aff_first_ok_img(mlx);
}
