#include "check_parenth.h"
#include "error.h"
#include "token.h"

static int		check_forward(char *str, unsigned int pos)
{
  unsigned int		i;
  int			ret;

  i = pos + 1;
  while (str[i] && str[i] > 0)
    i++;
  while (str[i] != '\0')
    {
      if (str[i] < 0)
	{
	  if ((ret = token_valid(str[i])) && ret > 0)
	    return (1);
	  else if (ret != -1)
	    {
	      if (str[i] == token_val(")"))
		return (!my_put_error(ERR_R_PARENTH, 0));
	      else
		return (!my_put_error(ERR_PARENTH, 0));
	    }
	}
      else
	return (!my_put_error(ERR_PARENTH, 0));
      i++;
    }
  return (1);
}

static unsigned int	init_count(unsigned int cpt,
				   char *str,
				   unsigned int pos)
{
  cpt = pos - 1;
  while (cpt > 0)
    {
      if (token_valid(str[cpt]) == 1)
	break ;
      cpt--;
    }
  cpt = cpt ? cpt + 1 : 0;
  return (cpt);
}

static unsigned int	check_next(char *str)
{
  unsigned int		nb;

  nb = 0;
  while (*str && *str < 0 && token_valid(*str))
    {
      str++;
      nb++;
    }
  while (*str && *str > 0)
    {
      str++;
      nb++;
    }
  return (nb);
}

static int		check_backwards(char *str, unsigned int pos)
{
  unsigned int	i;
  int		ret;

  i = init_count(i, str, pos);
  while (i < pos)
    if (str[i++] < 0)
      {
	if ((ret = token_valid(str[i - 1])) > 0)
	  if (ret != 2)
	    return (1);
	  else
	    i += check_next(&str[i - 1]);
	else if (ret != -1)
	  {
	    if (str[i - 1] == token_val(")"))
	      return (!my_put_error(ERR_R_PARENTH, 0));
	    else
	      return (!my_put_error(ERR_PARENTH, 0));
	  }
      }
    else
      return (!my_put_error(ERR_PARENTH, 0));
  return (1);
}

int		check_parenth(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 0 && str[i] == token_val("("))
	{
	  if (!check_backwards(str, i) || !check_forward(str, i))
	    return (0);
	}
      else if (str[i] < 0 && str[i] == token_val(")"))
	return (!my_put_error(ERR_R_PARENTH, 0));
      i++;
    }
  return (1);
}
