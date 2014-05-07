#include <string.h>
#include "struct.h"
#include "count_fcts.h"
#include "display_fcts.h"
#include "error.h"

int	built_echo(char **tab)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  if (tab[i] && !strcmp(tab[i], "-n"))
    {
      i++;
      j = 1;
    }
  while (tab[i])
    {
      my_putstr(tab[i]);
      if (tab[i + 1])
        my_putstr(" ");
      i++;
    }
  if (!j)
    my_putstr("\n");
  return (0);
}

int	built_exit(void)
{
  return (-1);
}
