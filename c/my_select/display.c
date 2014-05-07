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
char	*tgetstr();
int	tputs(const char *str, int affcnt, int (*putc)(int));

void	my_aff_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    my_putstr(tab[i++]);
}

void	aff_arg(t_area *ar)
{
  int	len2;
  int	len;
  int	i;

  i = 0;
  len = 0;
  len2 = 0;
  while (i != ar->ac)
    if (ar->res[i++] == 1)
      len++;
  i = 0;
  while (i != ar->ac)
    {
      if (ar->res[i] == 1)
	{
	  my_put_arg(ar->av[i]);
	  if (len2 < len)
	    {
	      my_put_arg(" ");
	      len2++;
	    }
	}
      i++;
    }
}

void	display_arguments(t_area *ar)
{
  ar->x = 1;
  ar->y = 0;
  while (ar->y < ar->ac)
    {
      tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
      my_putstr(ar->av[(ar->y)++]);
    }
  ar->x = 1;
  ar->y = 0;
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
}

void	aff_void(t_area *ar, int ac, int y)
{
  int	i;

  while (y != ac)
    {
      i = 0;
      while (i != ar->size)
	{
	  my_putchar(' ');
	  i++;
	}
      y++;
      tputs(x_tgoto(ar->cmstr, ar->x, y), 1, my_outc);
    }
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
}
