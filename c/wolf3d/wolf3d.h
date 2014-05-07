#ifndef WOLF3D_H_
# define WOLF3D_H_

/* Define rotation parameters */

#define NO	0
#define NE	1
#define EA	2
#define SE	3
#define SO	4
#define SW	5
#define WE	6
#define NW	7

/* Define PI */

#define PI	3.14159265

/* Window Size */

#define HEIGHT	600
#define WIDTH	800

/* Define colors */

#define GREY	"\033[1;30m"
#define RED	"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define PINK	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define DEFAULT	"\033[00m"

/* Define eroor messages */

#define ERR_MALLOC "FATAL error of 'malloc()' fonction.\n"

/* Struct */

typedef struct	s_lx
{
  char		**map;
  char		or[8];
  void		*mlx_ptr;
  void		*img_ptr;
  void		*win_ptr;
  unsigned char	*data;
  int		bpp;
  int		sizeline;
  int		endian;
  int		floor_cl;
  int		sky_cl;
  int		n_cl;
  int		s_cl;
  int		e_cl;
  int		w_cl;
  int		key_l;
  int		key_u;
  int		key_r;
  int		key_d;
  int		old_x;
  int		old_y;
  int		x;
  int		y;
  int		x_wall[WIDTH];
  int		y_wall[WIDTH];
  float		k[WIDTH];
  float		x1[WIDTH];
  float		y1[WIDTH];
  float		vx[WIDTH];
  float		vy[WIDTH];
  float		ang;
  short		flag_k;
}		t_lx;

/* Prototypes */

void	x_malloc_2d(char **tab, int size);
void	x_malloc(char *str, int size);
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_put_error(char *str);
int	my_strlen(char *str);
int	my_getnbr_base(char *str, char *base);
void	free_struct(t_lx *mlx);
int	gere_expose_img(t_lx *mlx);
void	aff_first_img(t_lx *mlx);
void	init(t_lx *mlx);
int	gere_key(int keycode, t_lx *mlx);
void	next(t_lx *mlx);
int	my_put_nbr(int n);
char	**my_tab_malloc(char **tab, int size1, int size2);
void	set_map(t_lx *mlx);
void	make_ku(t_lx *mlx);
void	make_kd(t_lx *mlx);
void	make_kr(t_lx *mlx);
void	make_kl(t_lx *mlx);
void    make_move_up(t_lx *mlx);
void    make_move_down(t_lx *mlx);
void	make_right_rotate(t_lx *mlx);
void	make_left_rotate(t_lx *mlx);
void	win_exit();
void	init_plan(t_lx *mlx);
void	aff_first_ok_img(t_lx *mlx);
void	drow_wall(t_lx *mlx);
void	calc_k(t_lx *mlx);
void	calc_vectors(t_lx *mlx);
void	my_pixel_put_to_image(int x, int y, t_lx *mlx);

/* MiniLibX Prototypes */

void		*mlx_init();
void		*mlx_new_window(void *mlx_ptr, int size_x,
                                int size_y, char *title);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr,
                              int x, int y, int color);
void		*mlx_new_image(void *mlx_ptr, int width, int height);
char		*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
                                   int *size_line, int *endian);
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
                                        void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);
int		mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop(void *mlx_ptr);
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
                               int color, char *string);
void		*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
                                  int *width, int *height);
void		*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
                                       int *width, int *height);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		mlx_hook(void *win_ptr, int x_event, int x_mask,
                         int (*funct)(), void *param);
int		mlx_do_key_autorepeatoff(void *mlx_ptr);
int		mlx_do_key_autorepeaton(void *mlx_ptr);
int		mlx_do_sync(void *mlx_ptr);

#endif /* WOLF3D_H_ */
