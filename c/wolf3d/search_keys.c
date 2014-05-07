#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void	make_kl(t_lx *mlx)
{
  int	i;

  i = 0;
  while (mlx->or[i] == 0)
    i++;
  if (i == NO)
    mlx->or[NE] = 1;
  else if (i == NE)
    mlx->or[EA] = 1;
  else if (i == EA)
    mlx->or[SE] = 1;
  else if (i == SE)
    mlx->or[SO] = 1;
  else if (i == SO)
    mlx->or[SW] = 1;
  else if (i == SW)
    mlx->or[WE] = 1;
  else if (i == WE)
    mlx->or[NW] = 1;
  else if (i == NW)
    mlx->or[NO] = 1;
  mlx->or[i] = 0;
  make_left_rotate(mlx);
}

void	make_kr(t_lx *mlx)
{
  int	i;

  i = 0;
  while (mlx->or[i] == 0)
    i++;
  if (i == NO)
    mlx->or[NW] = 1;
  else if (i == NE)
    mlx->or[NO] = 1;
  else if (i == EA)
    mlx->or[NE] = 1;
  else if (i == SE)
    mlx->or[EA] = 1;
  else if (i == SO)
    mlx->or[SE] = 1;
  else if (i == SW)
    mlx->or[SO] = 1;
  else if (i == WE)
    mlx->or[SW] = 1;
  else if (i == NW)
    mlx->or[WE] = 1;
  mlx->or[i] = 0;
  make_right_rotate(mlx);
}
