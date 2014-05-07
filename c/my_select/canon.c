#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stddef.h>
#include <sys/types.h>
#include "my_select.h"

int	my_tcgetattr(int fd, struct termios *t);
int	my_tcsetattr(int fd, int opt, struct termios *t);
int	tputs(const char *str, int affcnt, int (*putc)(int));

int	restore_mode(struct termios *oldline, t_area *ar)
{
  tputs(ar->clstr, 1, my_outc);
  xtcsetattr(0, TCSANOW, oldline);
  return (0);
}

int	my_tcgetattr(int fd, struct termios *t)
{
  int	tmp;

  tmp = xioctl(fd, TIOCGETA, t);
  return (tmp);
}

int			my_tcsetattr(int fd, int opt, struct termios *t)
{
  int			tmp;
  struct termios	l;

  my_ncpy(t, &l, sizeof(l));
  if (opt & TCSASOFT)
    l.c_cflag |= CIGNORE;
  if ((opt & ~TCSASOFT) == TCSANOW)
    {
      tmp = xioctl(fd, TIOCSETA, &l);
      return (tmp);
    }
  else if ((opt & ~TCSASOFT) == TCSADRAIN)
    {
      tmp = xioctl(fd, TIOCSETAW, &l);
      return (tmp);
    }
  else if ((opt & ~TCSASOFT) == TCSAFLUSH)
    {
      tmp = xioctl(fd, TIOCSETAF, &l);
      return (tmp);
    }
  return (-1);
}

int			non_canonical_mode(struct termios *oldline)
{
  struct termios	line;

  xtcgetattr(0, oldline);
  my_ncpy(oldline, &line, sizeof(line));
  line.c_lflag &= ~(ICANON | ECHO | ISIG);
  line.c_cc[VMIN] = 1;
  line.c_cc[VTIME] = 0;
  xtcsetattr(0, TCSANOW, &line);
  return (0);
}
