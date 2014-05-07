#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "my_select.h"

char	*tgoto(const char *cap, int col, int row);

void	x_malloc_2d(char **tab, int size)
{
  int	i;

  i = 0;
  if (tab == NULL)
    {
      my_put_error(ERR_MALLOC);
      exit(EXIT_FAILURE);
    }
  while (i != size)
    tab[i++] = NULL;
}

char	*x_tgoto(const char *cap, int col, int row)
{
  char	*tmp;

  tmp = tgoto(cap, col, row);
  if (tmp == NULL)
    {
      my_put_error(ERR_TGOTO);
      exit(EXIT_FAILURE);
    }
  return (tmp);
}

void	x_oth(int n)
{
  if (n == -1)
    {
      my_putstr(ERR_OTH);
      exit(EXIT_FAILURE);
    }
}
