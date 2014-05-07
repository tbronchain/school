#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void	make_kd_3(t_lx *mlx)
{
  if (mlx->or[WE] == 1)
    {
      if (mlx->map[mlx->y][mlx->x + 1] == 0)
	mlx->x++;
    }
  else if (mlx->or[NW] == 1)
    {
      if (mlx->map[mlx->y + 1][mlx->x + 1] == 0)
	{
	  mlx->x++;
	  mlx->y++;
	}
    }
}

void	make_kd_2(t_lx *mlx)
{
  if (mlx->or[SE] == 1)
    {
      if (mlx->map[mlx->y - 1][mlx->x - 1] == 0)
	{
	  mlx->x--;
	  mlx->y--;
	}
    }
  else if (mlx->or[SW] == 1)
    {
      if (mlx->map[mlx->y - 1][mlx->x + 1] == 0)
	{
	  mlx->x++;
	  mlx->y--;
	}
    }
  make_kd_3(mlx);
}

void	make_kd(t_lx *mlx)
{
  if (mlx->or[NO] == 1)
    {
      if (mlx->map[mlx->y + 1][mlx->x] == 0)
	mlx->y++;
    }
  else if (mlx->or[NE] == 1)
    {
      if (mlx->map[mlx->y + 1][mlx->x - 1] == 0)
	{
	  mlx->x--;
	  mlx->y++;
	}
    }
  else if (mlx->or[EA] == 1)
    {
      if (mlx->map[mlx->y][mlx->x - 1] == 0)
	mlx->x--;
    }
  else if (mlx->or[SO] == 1)
    {
      if (mlx->map[mlx->y - 1][mlx->x] == 0)
        mlx->y--;
    }
  make_kd_2(mlx);
}
