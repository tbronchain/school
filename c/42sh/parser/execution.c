#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "struct.h"
#include "builtins.h"
#include "builtins_cd.h"
#include "builtins_env.h"
#include "x_function_next.h"
#include "execution.h"
#include "error.h"
#include "x_function.h"
#include "wordtab.h"
#include "token.h"

int	kill(pid_t pid, int sig);

t_built		gl_built[] =
  {
    {"cd", built_cd},
    {"env", built_env},
    {"exit", built_exit},
    {"setenv", built_setenv},
    {"unsetenv", built_unsetenv},
    {"echo", built_echo},
    {0, 0}
  };

void	exec_fork(char **tab)
{
  signal(SIGINT, SIG_DFL);
  execvp(tab[0], tab);
  my_put_error(tab[0], 0);
  my_put_error(ERR_CMD_NOT_FOUND, 0);
  kill(getpid(), SIGUSR1);
  _exit(0);
}

int	exec(char **tab)
{
  pid_t	pid;
  int	sign;

  pid = xfork();
  if (pid)
    {
      xwaitpid(pid, &sign, WUNTRACED);
      if (sign)
        {
          if (sign < 256 && sign != SIGUSR1)
            psignal(sign, tab[0]);
          return (1);
        }
    }
  else
    exec_fork(tab);
  return (0);
}

int	search_exec(char **tab)
{
  int	ret;
  int	i;

  i = 0;
  while (gl_built[i].name && strcmp(gl_built[i].name, tab[0]))
    i++;
  if (gl_built[i].name)
    ret = gl_built[i].fct(tab);
  else
    ret = exec(tab);
  return (ret);
}

int	exec_command(char *command)
{
  char	**tab;
  int	ret;

  tab = str_to_wordtab(command, token_val(" "));
  if (!tab)
    return (1);
  ret = search_exec(tab);
  return (ret);
}
