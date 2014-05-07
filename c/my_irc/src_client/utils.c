#include <unistd.h>
#include <stdlib.h>

void	null(void *p)
{
  (void)p;
}

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
  while (tab[j] != NULL)
    {
      tab[j] = xfree(tab[j]);
      j++;
    }
  free(tab);
}

char	*str_clean(char *str, int len)
{
  int	i;

  i = 0;
  while (i != len)
    {
      if ((str[i] < 32 || str[i] > 126) && str[i] != '\n')
	str[i] = ' ';
      else if (str[i] == '\n')
	{
	  str[i + 1] = '\0';
	  return (str);
	}
      i++;
    }
  str[i] = '\n';
  str[i + 1] = '\0';
  return (str);
}
