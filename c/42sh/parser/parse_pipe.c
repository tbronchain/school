#include <stdlib.h>
#include "check_valid.h"
#include "error.h"
#include "token.h"
#include "wordtab.h"
#include "x_function.h"
#include "x_function_next.h"
#include "parse_pipe.h"
#include "parse_redir.h"

int	exec_father(char *command, int *p, int pid, int first)
{
  int	ret;

  xclose(p[1]);
  if (first)
    ret = xdup(0);
  if (first && ret < 0)
    return (pid);
  if (xdup2(p[0], 0) < 0)
    return (pid);
  parse_command_redir(command);
  xwaitpid(pid, 0, (first ? WNOHANG : WNOHANG & WUNTRACED));
  if (first && xdup2(ret, 0) < 0)
    return (pid);
  xclose(p[0]);
  xclose(ret);
  return (0);
}

int	parse_command_for_pipe(char **command, int tab_len, int first)
{
  int	p[2];
  int	pid;
  int	ret;

  if (xpipe(p) < 0)
    return (0);
  if ((pid = xfork()) > 0)
    {
      ret = exec_father(command[tab_len - 1], p, pid, first);
      if (ret > 0)
	return (ret);
    }
  else
    {
      xclose(p[0]);
      xdup2(p[1], 1);
      if (tab_len > 2)
	parse_command_for_pipe(command, tab_len - 1, 0);
      else
	parse_command_redir(command[0]);
      exit(0);
    }
  return (pid);
}

int	exec_pipe(char **command, int tab_len)
{
  int	pid;

  pid = parse_command_for_pipe(command, tab_len, 1);
  xwaitpid(pid, 0, WUNTRACED);
  return (0);
}

int	pipe_parsing(char *str)
{
  char	**tab_pipe;
  int	ret;
  int	tab_len;

  if (!valid_str(str) || !last_verif(str))
    return (0);
  if (in_str(str, token_val("|")) &&
      (tab_pipe = str_to_wordtab(str, token_val("|"))))
    {
      tab_len = count_tab(tab_pipe);
      ret = exec_pipe(tab_pipe, tab_len);
      free(tab_pipe);
    }
  else
    ret = parse_command_redir(str);
  return (ret);
}
