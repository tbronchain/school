#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_select.h"

int	my_strncpy(void *dest, void *src, int n)
{
  char	*dt;
  char	*sr;
  int	var;
  int	n_prov;
  int	count;

  sr = (char *)src;
  dt = (char *)dest;
  count = my_strlen(sr);
  var = 0;
  n_prov = n;
  while (var != n)
    {
      while (n_prov > 0)
	{
	  dt[var] = sr[var];
	  var = var + 1;
	  n_prov = n_prov - 1;
	  if (var > count + 1)
	    return (0);
	}
    }
  return (0);
}

void	my_ncpy(void *src, void *dest, int n)
{
  char	*src1;
  char	*src2;
  char 	*dest1;
  char 	*dest2;

  src1 = (char *)src;
  src2 = (char *)src + --n;
  dest1 = (char *)dest;
  dest2 = (char *)dest + n++;
  if (dest >= src)
    while (n != 0)
      {
	*dest2-- = *src2--;
	n--;
      }
  else
    while (n != 0)
      {
	*dest1++ = *src1++;
	n--;
      }
}

int	my_outc(int c)
{
  my_putchar(c);
  return (c);
}

void	my_arg_cpy(t_area *ar, char **argv, int argc)
{
  int	j;
  int	i;

  i = 0;
  j = 1;
  ar->av = malloc(argc * sizeof(*(ar->av)));
  x_malloc_2d(ar->av, argc);
  while (j != argc)
    {
      ar->av[i] = malloc(ar->size * sizeof(**(ar->av)));
      x_malloc(ar->av[i], ar->size);
      my_strcpy(ar->av[i++], argv[j++]);
    }
}

void	my_put_arg(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    write(1, &str[i++], 1);
}
