#include <sys/select.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur/serveur.h"
#include "serveur/lib.h"

void	*xfree(char *p)
{
  if (p)
    free(p);
  return (NULL);
}

void	free_tab(char **tab)
{
  int	j;

  j = 0;
  while (tab[j])
    {
      tab[j] = xfree(tab[j]);
      j++;
    }
  free(tab);
}

void		free_list(t_chan **list)
{
  t_chan	*tmp;

  while (*list)
    {
      tmp = (*list)->next;
      free(*list);
      *list = tmp;
    }
}
