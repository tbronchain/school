#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "wolf3d.h"

void	x_write(int x)
{
  if (x == -1)
    exit(EXIT_FAILURE);
}

void	my_putchar(char c)
{
  x_write(write(1, &c, 1));
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str != NULL)
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_put_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str != NULL)
    {
      x_write(write(2, &str[i], 1));
      i++;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str != NULL)
    i++;
  return (i);
}
