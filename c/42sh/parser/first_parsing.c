#include "struct.h"
#include "first_parsing.h"
#include "parenth.h"
#include "quote.h"
#include "token.h"

t_token	gl_token[] =
  {
    {" ",  -1,  1, 1, -1},
    {"\t", -1,  1, 1, -1},
    {";",  -2,  1, 1, 1},
    {"(",  -3,  1, 0, 0},
    {")",  -4,  1, 1, 0},
    {"&&", -7,  2, 1, 1},
    {"||", -8,  2, 1, 1},
    {"|",  -9,  1, 1, 1},
    {">>", -10, 2, 1, 2},
    {">",  -11, 1, 1, 2},
    {"<",  -12, 1, 1, 2},
    {0, 0, 0, 0, 0}
  };

static int	verif_token(char *str)
{
  int		i;
  int		flag;

  flag = 0;
   if ((i = check_token(str)) >= 0 && gl_token[i].replace)
    {
      flag = 1;
      gere_token(&str, i);
    }
   else if (*str == '\\')
    {
      flag = 1;
      i = 0;
      while (str[i])
	{
	  str[i] = str[i + 1];
	  i++;
	}
    }
  return (flag);
}

static int	gere_return(int (*fct)(), char **str, int opt)
{
  int		ret;

  ret = fct(str, opt);
  if (!ret)
    return (-1);
  else if (ret < 0)
    return (-ret);
  return (0);
}

int		first_parsing(char **buf, int opt)
{
  t_parsing	ps;

  ps.tmp = *buf;
  ps.save_tmp = ps.tmp;
  while (*ps.tmp)
    {
      if (verif_token(ps.tmp) == 0)
	{
	  if (*ps.tmp == '(')
	    {
	      if ((ps.ret = gere_return(gere_parenth, &ps.tmp, opt)))
		return (ps.ret);
	    }
	  else if (*ps.tmp == '\'' || *ps.tmp == '"')
	    if ((ps.ret = gere_return(gere_quote, &ps.tmp, opt)))
	      return (ps.ret);
  	}
      ps.tmp++;
    }
  *buf = ps.save_tmp;
  return (0);
}
