#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client/utils.h"
#include "client/x.h"

char	**str_to_wordtab(char *s)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (s[k] == ' ')
    k++;
  k--;
  tab = Xmalloc((strlen(s) + 1) * sizeof(char *));
  tab[0] = Xmalloc(strlen(s) + 1);
  while (s[++k])
    if (s[k] != ' ')
      tab[j][i++] = s[k];
    else if (s[k] == ' ' && s[k + 1] != ' ')
      {
	i = 0;
	tab[++j] = Xmalloc(strlen(s) + 1);
      }
  if (s[k - 1] == ' ')
    tab[j] = xfree(tab[j]);
  tab[j + 1] = NULL;
  return (tab);
}
