#include <stdlib.h>
#include "xfunction_termcap_next.h"
#include "xfunction_termcap.h"
#include "error.h"

char	*x_malloc(char *str, int size)
{
  int	i;

  i = 0;
  str = malloc(size * sizeof(*str));
  if (str == NULL)
    {
      my_put_error("malloc", 0);
      exit(EXIT_FAILURE);
    }
  while (i != size)
    str[i++] = 0;
  return (str);
}

char	**xmalloc_2d(char **tabs, int size)
{
  int	i;

  i = 0;
  tabs = malloc(size * sizeof(*tabs));
  if (tabs == NULL)
      my_put_error("Error with malloc.\n", 0);
  while (i != size)
    tabs[i++] = NULL;
  return (tabs);
}

void	xtputs(char *str, int affcnt, int (*my_outc)(int))
{
  if (tputs(str, affcnt, my_outc) < 0)
    my_put_error("tputs failed.\n", 1);
}
