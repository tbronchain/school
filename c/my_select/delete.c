#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stddef.h>
#include "my_select.h"

int	tputs(const char *str, int affcnt, int (*putc)(int));
int	my_tcgetattr(int fd, struct termios *t);
int	my_tcsetattr(int fd, int opt, struct termios *t);
int	non_canonical_mode(struct termios *oldline);
int	restore_mode(struct termios *oldline, t_area *ar);

void	make_delete_mid(t_area *ar, int ac, int y)
{
  while (y != ar->ac - 1)
    {
      x_malloc(ar->av[y], ar->size);
      my_strcpy(ar->av[y], ar->av[y + 1]);
      ar->res[y] = ar->res[y + 1];
      y++;
    }
  ar->ac--;
  y = ar->y;
  aff_void(ar, ac, y);
  while (y != ar->ac)
    {
      if (ar->res[y] == 1)
	{
	  tputs(ar->sostr, 1, my_outc);
	  my_putstr(ar->av[y]);
	  tputs(ar->sestr, 1, my_outc);
	}
      else
	my_putstr(ar->av[y]);
      tputs(x_tgoto(ar->cmstr, ar->x, ++y), 1, my_outc);
    }
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
}

void	make_delete_end(t_area *ar, int y)
{
  int	i;

  i = 0;
  while (i != ar->size)
    {
      my_putchar(' ');
      i++;
    }
  ar->res[y] = 0;
  ar->ac--;
  ar->y = 0;
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
}

int	check_delete(t_area *ar)
{
  int	ac;
  int	y;

  ac = ar->ac;
  y = ar->y;
  if ((ar->buff[0] == BSP && ar->len == 1) ||
      (ar->buff[0] == 27 && ar->buff[1] == 91 &&
       ar->buff[2] == 51 && ar->buff[3] == 126 && ar->len == 4))
    {
      if (ac == 1)
	{
	  free_struct(ar);
	  return (-1);
	}
      else if (y < ac - 1)
	make_delete_mid(ar, ac, y);
      else
	make_delete_end(ar, y);
    }
  return (0);
}
