#include "wolf3d.h"

int	my_puiss(int n)
{
  int	count;
  int	puiss;

  count = 0;
  puiss = 1;
  while (n >= 10)
    {
      n = (n / 10);
      count = count + 1;
    }
  while (count > 0)
    {
      puiss = (puiss * 10);
      count = (count - 1);
    }
  return (puiss);

}

int	my_put_nbr(int n)
{
  int	ret;
  int	div;

  if (n < 0)
    {
      my_putchar('-');
      n = n * (-1);
    }
  div = n;
  ret = my_puiss(n);
  while (ret >= 1)
    {
      div = div / ret;
      my_putchar(div + 48);
      div = n % ret;
      ret = ret / 10;
    }
  return (n);
}
