#include "error.h"
#include "token.h"
#include "check_valid.h"

static int	check_r_redir(char *str)
{
  int		i;

  i = 0;
  while (*str)
    {
      if (!i && *str == token_val(">"))
	{
	  i = 1;
	  str++;
	}
      else if (i && (*str == token_val("|")
		     || *str == token_val(">")))
	{
	  my_put_error(ERR_REDIR, 0);
	  return (0);
	}
	str++;
    }
  return (1);
}

static int	check_l_redir(char *str)
{
  int		i;

  i = 0;
  while (*str)
    {
      if (!i && *str == token_val("<"))
	{
	  i = 1;
	  str++;
	}
      else if (i && (*str == token_val("|")
		     || *str == token_val("<")))
	{
	  my_put_error(ERR_REDIR, 0);
	  return (0);
	}
	str++;
    }
  return (1);
}

int	last_verif(char *str)
{
  int	ok;

  ok = 1;
  if (ok)
    ok = check_r_redir(str);
  if (ok)
    ok = check_l_redir(str);
  return (ok);
}

static int	count_in_pipe(char *str)
{
  int		word;
  int		nb;

  word = 1;
  nb = 0;
  while (*str)
    {
      if (*str == token_val("|"))
	word = 1;
      else if (word == 1 && *str > 0)
	{
	  nb++;
	  word = 0;
	}
      str++;
    }
  return (nb);
}

int	valid_str(char *str)
{
  int	nb;
  int	pipe;

  pipe = 0;
  nb = count_in_pipe(str);
  while (*str)
    {
      if (*str == token_val("|"))
	pipe++;
      str++;
    }
  if (!pipe)
    return (1);
  if (nb == pipe + 1)
    return (1);
  my_put_error("Error: Invalid null command.\n", 0);
  return (0);
}
