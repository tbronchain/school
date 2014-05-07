#include <stdlib.h>
#include <signal.h>
#include "struct.h"
#include "init_parsing.h"
#include "list_for_env.h"
#include "get_command.h"
#include "init_env.h"
#include "error.h"

int		freelist(t_list **begin)
{
  t_list	*tmp;

  while (*begin)
    {
      tmp = (*begin)->next;
      free((*begin)->data);
      free(*begin);
      *begin = tmp;
    }
  return (0);
}

void	end_free(int test_env)
{
  if (test_env != -1)
    {
      freelist(&(my_env.begin));
      free_tab(my_env.path);
      free_tab(my_env.my_environ);
      free(my_env.pwd);
    }
}

int	first_check(int env)
{
  if (test_env(my_env.my_environ) == -1)
    {
      end_free(env);
      my_put_error("Missing some ENV variables, New copy will be created.\n", 0);
      env = init_env();
    }
  return (env);
}

int	main()
{
  char	*str;
  int	env;

  env = init_env();
  str = NULL;
  while (42)
    {
      signal(SIGINT, SIG_IGN);
      first_check(env);
      str = get_command_termcap("$>");
      if (str != NULL)
	{
	  if (*str)
	    {
	      signal(SIGINT, SIG_IGN);
	      if (init_parsing(&str) < 0)
		break ;
	    }
	  free(str);
	}
    }
  end_free(env);
  if (str != NULL)
    free(str);
  return (0);
}
