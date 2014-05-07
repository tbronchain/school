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
int	restore_mode(struct termios *oldline);
char	*tgetstr();

void	x_tgetstr(char *capstr, char *cap)
{
  if (capstr == NULL)
    {
      my_put_error(ERR_TGETSTR);
      my_put_error(cap);
      exit(EXIT_FAILURE);
    }
}

char	*xtgetstr(char *cap, char **area)
{
  char	*capstr;

  capstr = tgetstr(cap, area);
  x_tgetstr(capstr, cap);
  return (capstr);
}
