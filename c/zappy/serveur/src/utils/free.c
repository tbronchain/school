#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "utils/free.h"
#include "utils/x.h"

void	*xfree(char *p)
{
  if (p)
    free(p);
  return (NULL);
}

void	*free_tab(char **tab)
{
  int	j;

  j = 0;
  while (tab[j])
    {
      tab[j] = xfree(tab[j]);
      j++;
    }
  free(tab);
  return (NULL);
}
