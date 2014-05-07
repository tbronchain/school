#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils/lib.h"
#include "utils/free.h"
#include "utils/x.h"

char	*str_clean(char *str)
{
  int	i;
  int	k;

  i = 0;
  while (str[i])
    {
      k = i;
      if (str[i] < 32 || str[i] > 126)
	str[i] = '\0';
      else
	i++;
    }
  return (str);
}

char	**verif_wordtab(char *buf, char token)
{
  char	**cmd;

  if (!(cmd = str_to_wordtab(buf, token)))
    return (NULL);
  else if (!cmd[0])
    {
      free_tab(cmd);
      return (NULL);
    }
  else if (!strlen(cmd[0]))
    {
      free_tab(cmd);
      return (NULL);
    }
  return (cmd);
}

char	**str_to_wordtab(char *s, char token)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (s[k] == token && s[k])
    k++;
  k--;
  tab = Xmalloc((strlen(s) + 2) * sizeof(char *));
  tab[0] = Xmalloc((strlen(s)) + 2 * sizeof(char));
  while (s[++k])
    if (s[k] != token)
      tab[j][i++] = s[k];
    else if (s[k] == token && s[k + 1] != token && s[k + 1])
      {
	i = 0;
	tab[++j] = Xmalloc(strlen(s) + 1);
      }
  return (tab);
}

int	count(char **p)
{
  int	i;

  i = 0;
  while (p[i])
    i++;
  return (i);
}

int	get_block(int nb)
{
  int	tmp;
  int	res;

  tmp = 1;
  res = 2;
  while (res < nb)
    {
      res *= 2;
      tmp++;
    }
  return (tmp);
}
