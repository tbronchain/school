#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "utils.h"

int	my_str_isprintable(char *str)
{
  int	b;

  b = 0;
  while (str[b] != '\0')
    {
      if ((str[b] > '~') || (str[b] < ' '))
        return (0);
      b = b + 1;
    }
  return (1);
}

void	my_putchar(char c)
{
  int	i;

  if ((i = write(0, &c, 1)) == -1)
    my_put_error("Error with write\n", 0);
}

char	*my_xmalloc(char *str, int size)
{
  int	i;

  i = 0;
  str = malloc(sizeof (*str) * size);
  if (str == NULL)
    my_put_error("Alocation failed\n", 1);
  while (i != size)
    {
      str[i] = 0;
      i++;
    }
  return (str);
}
