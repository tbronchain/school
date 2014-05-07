#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include "serveur/serveur.h"
#include "serveur/x.h"
#include "serveur/free.h"

char	*concat(char **p, int j)
{
  char	*res;

  res = Xmalloc(1);
  while (p[j])
    {
      res = X(NULL, realloc(res, strlen(res) + strlen(p[j]) + 2), "realloc");
      strcat(res, p[j]);
      j++;
      if (p[j])
	strcat(res, " ");
    }
  return (res);
}

char	*str_clean(char *str)
{
  int	i;
  int	k;

  i = 0;
  while (str[i])
    {
      k = i;
      if (str[i] < 32 || str[i] > 126)
	while (str[k])
	  {
	    str[k] = str[k + 1];
	    k++;
	  }
      else
	i++;
    }
  return (str);
}

char	*my_strcat(char *s1, char *s2)
{
  char	*res;

  res = Xmalloc(strlen(s1) + strlen(s2) + 2);
  strcpy(res, s1);
  strcat(res, s2);
  return (res);
}

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

void	sort_tab(char **p)
{
  char	tmp[CHAN_LEN + NICK_LEN + 2];
  int	flag;
  int	j;

  flag = 1;
  while (flag)
    {
      flag = 0;
      j = 0;
      while (p[j + 1])
        {
          if (strcmp(p[j], p[j + 1]) > 0)
            {
              strcpy(tmp, p[j]);
              strcpy(p[j], p[j + 1]);
              strcpy(p[j + 1], tmp);
              flag = 1;
            }
          j++;
        }
    }
}
