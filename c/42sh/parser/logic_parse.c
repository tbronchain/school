#include <stdlib.h>
#include "error.h"
#include "token.h"
#include "x_function.h"
#include "parse_pipe.h"
#include "logic_parse.h"

static void		add_list(t_logic **lg, char *command, int and_or)
{
  static t_logic	*last = 0;
  t_logic		*new;

  if (command)
    {
      new = xmalloc(sizeof(*new));
      new->command = command;
      new->and_or = and_or;
      new->next = 0;
      if (!last)
	*lg = new;
      else
	last->next = new;
      last = new;
    }
  else
    last = 0;
}

static t_logic	*move_in_list(char * command)
{
  t_logic	*lg;
  int		and_or;

  lg = 0;
  and_or = -1;
  while (*command && *command != token_val("||")
	 && *command != token_val("&&"))
    {
      add_list(&lg, command, and_or);
      while (*command && *command != token_val("||")
	     && *command != token_val("&&"))
	command++;
      if (!(*command))
	break;
      and_or = (*command != token_val("||") ? 0 : 1);
      *command = 0;
      command++;
    }
  add_list(0, 0, 0);
  return (lg);
}

static int	*count_loop(char *str)
{
  int		word;
  int		*nb;

  word = 1;
  nb = xmalloc(2 * sizeof(*nb));
  nb[0] = 0;
  nb[1] = 0;
  while (*str)
    {
      if (*str == token_val("||") || *str == token_val("&&"))
	{
	  nb[0]++;
	  str++;
	  word = 1;
	}
      else if (word && *str != token_val(" "))
	{
	  word = 0;
	  nb[1]++;
	}
      str++;
    }
  return (nb);
}

static int	check_error(char *command)
{
  int		*nb;

  nb = count_loop(command);
  if (!nb[0])
    {
      free(nb);
      return (pipe_parsing(command));
    }
  if (nb[0] >= nb[1])
    {
      free(nb);
      return (my_put_error(ERR_CMD, 0));
    }
  free(nb);
  return (-2);
}

int		logic_parse(char *command)
{
  t_logic_v	lv;

  if ((lv.ret = check_error(command)) != -2)
    return (lv.ret);
  lv.quit = 0;
  lv.lg = move_in_list(command);
  lv.skip = 0;
  lv.ret = 0;
  while (lv.lg)
    {
      if (!lv.skip)
        lv.ret = pipe_parsing((lv.lg)->command);
      lv.skip = 0;
      if ((lv.lg)->next && ((lv.ret > 0 && !((lv.lg)->next->and_or))
			    || (!(lv.ret) && (lv.lg)->next->and_or)))
	lv.skip = 1;
      if (lv.ret < 0)
        lv.quit = 1;
      lv.tmp = lv.lg;
      lv.lg = (lv.lg)->next;
      free(lv.tmp);
    }
  if (lv.quit)
    return (-1);
  return (0);
}
