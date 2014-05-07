#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

typedef struct	s_st
{
  int		xmin;
  int		ymin;
  t_lx		*mlx;
}		t_st;

void	setmap_to_zero(t_lx *mlx, t_st st, int ymax, int xmax)
{
  int	xmin;
  int	ymin;

  ymin = st.ymin;
  while (ymin <= ymax)
    {
      xmin = st.xmin;
      while (xmin <= xmax)
	{
	  mlx->map[ymin][xmin] = 0;
	  xmin++;
	}
      ymin++;
    }
}

void	setmap_to_one(t_lx *mlx, t_st st, int ymax, int xmax)
{
  int	xmin;
  int	ymin;

  ymin = st.ymin;
  while (ymin <= ymax)
    {
      xmin = st.xmin;
      while (xmin <= xmax)
	{
	  mlx->map[ymin][xmin] = 1;
	  xmin++;
	}
      ymin++;
    }
}

void	set_map_oth_val(t_lx *mlx)
{
  mlx->x = 22;
  mlx->y = 34;
  mlx->map[4][5] = 2;
  mlx->map[4][6] = 2;
  mlx->map[4][7] = 2;
  mlx->map[4][8] = 2;
  mlx->map[4][9] = 2;
}

void	set_map_oth(t_lx *mlx, t_st st)
{
  st.ymin = 30;
  st.xmin = 5;
  setmap_to_zero(mlx, st, 34, 29);
  st.ymin = 5;
  st.xmin = 20;
  setmap_to_zero(mlx, st, 24, 24);
  st.ymin = 10;
  st.xmin = 25;
  setmap_to_zero(mlx, st, 14, 29);
  st.ymin = 20;
  st.xmin = 25;
  setmap_to_zero(mlx, st, 29, 29);
  st.ymin = 5;
  st.xmin = 30;
  setmap_to_zero(mlx, st, 19, 34);
  st.ymin = 25;
  st.xmin = 30;
  setmap_to_zero(mlx, st, 29, 34);
  st.ymin = 15;
  st.xmin = 15;
  setmap_to_zero(mlx, st, 19, 19);
  set_map_oth_val(mlx);
}

void	set_map(t_lx *mlx)
{
  t_st	st;

  st.ymin = 0;
  st.xmin = 0;
  setmap_to_one(mlx, st, 39, 39);
  st.ymin = 5;
  st.xmin = 5;
  setmap_to_zero(mlx, st, 9, 14);
  st.ymin = 10;
  st.xmin = 10;
  setmap_to_zero(mlx, st, 14, 14);
  st.ymin = 15;
  st.xmin = 5;
  setmap_to_zero(mlx, st, 34, 14);
  st.ymin = 25;
  st.xmin = 10;
  setmap_to_one(mlx, st, 29, 14);
  set_map_oth(mlx, st);
}
