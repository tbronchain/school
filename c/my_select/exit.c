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

void	free_struct(t_area *ar)
{
  free(ar->term);
  free(ar->res);
  free(ar->av);
}

int	my_exit(struct termios *oldline, t_area *ar)
{
  if (ar->buff[0] == ESC && ar->len == 1)
    {
      free_struct(ar);
      restore_mode(oldline, ar);
      return (1);
    }
  else if (ar->buff[0] == RET && ar->len == 1)
    {
      aff_arg(ar);
      free_struct(ar);
      restore_mode(oldline, ar);
      return (1);
    }
  return (0);
}

int	void_exit(t_area *ar, struct termios *oldline)
{
  if (check_delete(ar) == -1)
    {
      free_struct(ar);
      restore_mode(oldline, ar);
      return (1);
    }
  return (0);
}
