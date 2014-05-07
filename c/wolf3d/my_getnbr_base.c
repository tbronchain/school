#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "wolf3d.h"

int	find_pos(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      i = i + 1;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	result;
  int	len_base;
  int	len_str;
  int	fact;

  if (str[0] == '-')
    return (-my_getnbr_base(&str[1], base));
  fact = 1;
  len_base = my_strlen(base);
  len_str = my_strlen(str) - 1;
  result = 0;
  while (len_str >= 0)
    {
      result = result + find_pos(str[len_str], base) * fact;
      fact = len_base * fact;
      len_str = len_str - 1;
    }
  return (result);
}
