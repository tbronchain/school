#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "my_select.h"

void	*xmalloc(int size)
{
  void	*p;
  char	*tmp;
  int	i;

  i = 0;
  p = malloc(size);
  if (str == NULL)
    {
      my_put_error(ERR_MALLOC);
      exit(EXIT_FAILURE);
    }
  tmp = (char *)p;
  while (i != size)
    tmp[i++] = 0;
  return (p);
}

void	xread(int fd, char *buf, int len)
{
  int	n;

  n = read(fd, buf, len);
  if (n < 0)
    {
      my_put_error(ERR_READ);
      exit(EXIT_FAILURE);
    }
}

void	xtcgetattr(int fd, void *t)
{
  int	n;

  n = my_tcgetattr(fd, t);
  if (n < 0)
    {
      my_put_error(ERR_TCGET);
      exit(EXIT_FAILURE);
    }
}

void	xtcsetattr(int fd, int opt, void *t)
{
  int	n;

  n = my_tcgetattr(fd, opt, t);
  if (n < 0)
    {
      my_put_error(ERR_TCSET);
      exit(EXIT_FAILURE);
    }
}

void	xtgetent(int n)
{
  if (n != 1)
    {
      my_put_error(ERR_TGETENT);
      exit(EXIT_FAILURE);
    }
}
