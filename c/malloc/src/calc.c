#include <stdlib.h>
#include "struct.h"

void		init()
{
  static int	flag = 0;
  int		i;

  if (flag)
    return ;
  i = 0;
  flag = 1;
  gl_alloc = NULL;
  while (i < 32)
    buckets[i++] = NULL;
}

int	my_power(int nb, int power)
{
  int	res;
  int	i;

  i = 0;
  res = nb;
  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  while (++i < power)
    res *= nb;
  return (res);
}

unsigned int	get_power(unsigned int nb)
{
  unsigned int	tmp;
  unsigned int	res;

  tmp = 1;
  res = 2;
  while (res < nb)
    {
      res *= 2;
      tmp++;
    }
  return (tmp);
}

unsigned int	get_block_size(unsigned int len)
{
  unsigned int	nb;
  unsigned int	tmp;

  nb = 1;
  tmp = 0;
  while (tmp < len)
    {
      if (nb > 31)
	return (0);
      tmp = my_power(2, nb);
      nb++;
    }
  return (tmp);
}
