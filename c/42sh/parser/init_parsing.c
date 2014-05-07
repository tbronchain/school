#include <stdlib.h>
#include "init_parsing.h"
#include "first_parsing.h"
#include "check_parenth.h"
#include "wordtab.h"
#include "token.h"
#include "logic_parse.h"

int	init_parsing(char **buf)
{
  int	i;
  int	ret;
  char	**tab;

  i = 0;
  ret = first_parsing(buf, 0);
  if (ret < 0)
    return (0);
  if (!check_parenth(*buf))
    return (0);
  tab = str_to_wordtab(*buf, token_val(SEMICOLON));
  if (!tab)
    return (0);
  ret = 0;
  while (tab[i])
      ret = logic_parse(tab[i++]);
  free(tab);
  return (ret);
}
