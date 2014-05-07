#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stddef.h>
#include "my_select.h"

int	my_tcgetattr(int fd, struct termios *t);
int	my_tcsetattr(int fd, int opt, struct termios *t);
int	non_canonical_mode(struct termios *oldline);
int	restore_mode(struct termios *oldline, t_area *ar);
int	void_exit(t_area *ar, struct termios *oldline);
int	my_exit(struct termios *oldline, t_area *ar);
char	*tgetstr();
int	tputs(const char *str, int affcnt, int (*putc)(int));

int	make_argc(t_area *ar, int argc)
{
  if (argc >= (ar->li - 1))
    argc = ar->li - 2;
  return (argc);
}

void	make_search_sel(t_area *ar, char *stck)
{
  int	i;

  i = 0;
  ar->x = 1;
  while (i != ar->ac)
    {
      if (my_strcmp(ar->av[i], stck) == 1)
	{
	  ar->y = i;
	  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
	  tputs(ar->sostr, 1, my_outc);
	  ar->res[ar->y] = 1;
	  my_putstr(ar->av[ar->y]);
	  tputs(ar->sestr, 1, my_outc);
	}
      i++;
    }
}

int	make_search(t_area *ar)
{
  char	stck[1024];
  char	buff[1024];
  int	rd;
  int	i;

  i = 0;
  ar->y = ar->li - 1;
  ar->x = 0;
  my_putstr("Enter your search : ");
  while ((rd = read(0, buff, sizeof(buff))))
    {
      x_read(rd);
      if (buff[0] == RET)
	{
	  stck[i] = '\0';
	  make_search_sel(ar, stck);
	  return (0);
	}
      else if (buff[0] >= 32 && buff[0] <= 126 && i < (ar->co - 21) && i < 1024)
	{
	  my_putchar(buff[0]);
	  stck[i++] = buff[0];
	}
    }
  return (0);
}

void	erase_lines(t_area *ar)
{
  ar->y = ar->li - 2;
  ar->x = 0;
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
  while (ar->x < ar->co)
    {
      my_putchar(' ');
      ar->x++;
    }
  ar->y = ar->li - 1;
  ar->x = 0;
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
  while (ar->x < ar->co)
    {
      my_putchar(' ');
      ar->x++;
    }
}

void	check_ctrl(t_area *ar)
{
  int	x;
  int	y;

  x = ar->x;
  y = ar->y;
  if (ar->buff[0] == 's' && ar->len == 1)
    {
      ar->y = ar->li - 2;
      ar->x = 0;
      tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
      while (ar->x < ar->co)
	{
	  tputs(ar->sostr, 1, my_outc);
	  my_putchar(' ');
	  ar->x++;
	}
      tputs(ar->sestr, 1, my_outc);
      make_search(ar);
      erase_lines(ar);
      ar->y = y;
      ar->x = x;
      tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
    }
}
