#include "struct.h"
#include "parenth.h"
#include "error.h"
#include "token.h"

static int	next_quote(char *str, int quote)
{
  int		i;

  i = 0;
  while (str[i] && str[i] == (quote ? '"' : '\''))
    i++;
  return (i - 1);
}

static int	count_quote(char *str, int nb)
{
  while (*str)
    {
      if (*str == '\\')
        str++;
      else if (*str == '\'' || *str == '"')
        nb += next_quote(str, *str == '\'' ? 0 : 1);
      else if (*str == '(')
        nb++;
      else if (*str == ')')
        nb--;
      if (!nb)
        break ;
      str++;
    }
  return (nb);
}

int	gere_parenth(char **arg, int opt)
{
  char	*str;
  int	nb;
  int	i;

  str = *arg;
  *(str++) = token_val("(");
  nb = 1;
  i = 0;
  nb = count_quote(str, nb);
  if (nb > 0 && !opt)
    return (!my_put_error(ERR_L_PARENTH, 0));
  i = 0;
  while (str[i])
    {
      str[i] = str[i + 1];
      i++;
    }
  *arg = str - 1;
  return (1);
}
