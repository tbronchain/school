#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "wolf3d.h"

void	calc_first_img(t_lx *mlx)
{
  float	x1;
  float	y1;
  int	i;

  i = 0;
  while (i < WIDTH)
    {
      x1 = mlx->x1[i]*cos(mlx->ang) - mlx->y1[i]*sin(mlx->ang);
      y1 = mlx->x1[i]*sin(mlx->ang) + mlx->y1[i]*cos(mlx->ang);
      mlx->x1[i] = x1 + mlx->x;
      mlx->y1[i] = y1 + mlx->y;
      i++;
    }
}

void	calc_vectors(t_lx *mlx)
{
  int	i;

  i = 0;
  while (i < WIDTH)
    {
      mlx->vx[i] = mlx->x1[i] - mlx->x;
      mlx->vy[i] = mlx->y1[i] - mlx->y;
      i++;
    }
}

void	calc_k(t_lx *mlx)
{
  char	flag;
  int	i;

  i = 0;
  while (i < WIDTH)
    {
      flag = 0;
      mlx->k[i] = 0;
      while (flag == 0)
	{
	  mlx->x_wall[i] = (int)(mlx->x + mlx->k[i] * mlx->vx[i]);
	  mlx->y_wall[i] = (int)(mlx->y + mlx->k[i] * mlx->vy[i]);
	  if (mlx->y_wall[i] < 40 && mlx->x_wall[i] < 40)
	    if (mlx->map[mlx->y_wall[i]][mlx->x_wall[i]] == 1)
	      flag = 1;
	  mlx->k[i] += 0.01;
	}
      if (mlx->k[i++] < 0.5)
	{
	  mlx->flag_k = 1;
	  i = WIDTH;
	}
    }
}

void	drow_wall(t_lx *mlx)
{
  int	j;
  int	i;
  int	imax;

  aff_first_img(mlx);
  j = 0;
  while (j < WIDTH)
    {
      i = (int)(((HEIGHT/2) - HEIGHT/(2*mlx->k[j])));
      imax = (int)(((HEIGHT/2) + HEIGHT/(2*mlx->k[j])));
      while (i <= imax)
	my_pixel_put_to_image(j, i++, mlx);
      j++;
    }
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void	aff_first_ok_img(t_lx *mlx)
{
  mlx->flag_k = 0;
  init_plan(mlx);
  calc_first_img(mlx);
  calc_vectors(mlx);
  calc_k(mlx);
  if (mlx->flag_k == 0)
    drow_wall(mlx);
}
