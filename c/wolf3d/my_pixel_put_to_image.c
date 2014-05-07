#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

void    my_pixel_put_to_image(int x, int y, t_lx *mlx)
{
  int	line;
  int	byte;
  int	res;

  line = y * WIDTH * ((mlx->bpp)/8);
  byte = x * 2;
  res = (line + byte);
  mlx->data[res] = 160;
  mlx->data[res + 1] = 160;
}
