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

void	aff_old_select(t_area *ar)
{
  if (ar->res[ar->y] == 0)
    my_putstr(ar->av[ar->y]);
  else
    {
      tputs(ar->sostr, 1, my_outc);
      my_putstr(ar->av[(ar->y)]);
      tputs(ar->sestr, 1, my_outc);
    }
}

void	aff_new_select(t_area *ar)
{
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
  tputs(ar->usstr, 1, my_outc);
  if (ar->res[ar->y] == 0)
    my_putstr(ar->av[(ar->y)]);
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
  tputs(ar->uestr, 1, my_outc);
}

void	check_keys(t_area *ar, int len)
{
  if (ar->buff[0] == 27 && ar->buff[1] == 91 && ar->buff[2] == KU && len == 3)
    {
      aff_old_select(ar);
      tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
      if (ar->y == 0)
	ar->y = ar->ac - 1;
      else
	ar->y--;
      aff_new_select(ar);
    }
  if (ar->buff[0] == 27 && ar->buff[1] == 91 && ar->buff[2] == KD && len == 3)
    {
      aff_old_select(ar);
      if (ar->y == ar->ac - 1)
	ar->y = 0;
      else
	ar->y++;
      aff_new_select(ar);
    }
}

void	check_select(t_area *ar)
{
  if (ar->buff[0] == SP && ar->len == 1)
    {
      if (ar->res[ar->y] == 0)
	{
	  ar->res[ar->y] = 1;
	  tputs(ar->sostr, 1, my_outc);
	  my_putstr(ar->av[ar->y]);
	  tputs(ar->sestr, 1, my_outc);
	  if (ar->y == ar->ac - 1)
	    ar->y = 0;
	  else
	    ar->y++;
	}
      else if (ar->res[ar->y] == 1)
	{
	  ar->res[ar->y] = 0;
	  my_putstr(ar->av[ar->y]);
	  if (ar->y == ar->ac - 1)
	    ar->y = 0;
	  else
	    ar->y++;
	}
      tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
    }
}
