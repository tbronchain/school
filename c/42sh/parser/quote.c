#include "struct.h"
#include "error.h"
#include "quote.h"

static void	parse_quote(t_quote *qt)
{
  while (qt->str[qt->j + 1])
    {
      qt->str[qt->j] = qt->str[qt->j + 1];
      qt->j++;
    }
  qt->str[qt->j] = 0;
  while (*qt->str && ((qt->quote && *qt->str != '"')
		      || (!qt->quote && *qt->str != '\'')))
    {
      if (*qt->str == '\\' && *(qt->str + 1) &&
	  *(qt->str + 1) == (qt->quote ? '"' : '\'') && *(qt->str + 2))
	{
	  qt->j = 0;
	  while (qt->str[qt->j])
	    {
	      qt->str[qt->j] = qt->str[qt->j + 1];
	      qt->j++;
	    }
	}
      qt->str++;
    }
}

int		gere_quote(char **arg, int opt)
{
  t_quote	qt;

  qt.j = 0;
  qt.str = *arg;
  qt.quote = (*qt.str == '"' ? 1 : 0);
  parse_quote(&qt);
  if (!*qt.str && !opt)
    return (!my_put_error((qt.quote ? DOUBLE_Q : SIMPLE_Q), 0));
  else if (!*qt.str && opt)
    return (qt.quote ? -2 : -1);
  qt.j = 0;
  while (qt.str[qt.j + 1])
    {
      qt.str[qt.j] = qt.str[qt.j + 1];
      qt.j++;
    }
  qt.str[qt.j] = 0;
  qt.str--;
  *arg = qt.str;
  return (1);
}
