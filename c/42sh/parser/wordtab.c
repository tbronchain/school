#include "wordtab.h"
#include "x_function.h"

int	in_str(char *str, char to_test)
{
  while (*str)
    {
      if (to_test == *str)
	return (1);
      str++;
    }
  return (0);
}

int	count_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

static int	count_cut(char *str, char cut)
{
  int		word;
  int		nb;

  word = 1;
  nb = 0;
  while (*str)
    {
      if (cut == *str)
        word = 1;
      else if (word == 1)
        {
          nb++;
          word = 0;
        }
      str++;
    }
  return (nb);
}

char	**str_to_wordtab(char *str, char cut)
{
  char	**tab;
  int	nb;
  int	i;

  if (!(nb = count_cut(str, cut)))
    return (0);
  tab = xmalloc((nb + 1) * sizeof(*tab));
  i = 0;
  while (*str)
    {
      while (*str && *str == cut)
        *(str++) = 0;
      if (*str)
        tab[i++] = str;
      while (*str && *str != cut)
        str++;
    }
  tab[i] = 0;
  return (tab);
}
