#include <stdlib.h>
#include "struct.h"
#include "check_redir.h"
#include "error.h"
#include "x_function_next.h"
#include "modif_str_fcts.h"
#include "make_redir.h"
#include "parse_redir.h"
#include "token.h"

t_pipe	gl_pipe[] =
  {
    {0, exec_command},
    {1, parse_command_r_redir},
    {2, parse_command_l_redir}
  };

int	get_mask(char *command)
{
  while (*command && *command != token_val(">")
	 && *command != token_val(">>"))
    command++;
  if (!(*command))
    return (0);
  if (*command == token_val(">"))
    return (O_CREAT | O_WRONLY | O_TRUNC);
  else
    return (O_CREAT | O_WRONLY | O_APPEND);
}

char	*check_name(char **command)
{
  char		*str;

  str = *command;
  while (*str && *str != token_val(">")
	 && *str != token_val(">>"))
    str++;
  if (!(*str))
    return ((char *)0);
  return (go_after(command, *str));
}

int	parse_command_redir(char *command)
{
  int	ret;
  char	*tmp;
  char	*res;

  ret = 1;
  res = my_strdup(command);
  tmp = command;
  while (*tmp && *tmp != token_val(">") && *tmp != token_val("<")
	 && *tmp != token_val(">>"))
    tmp++;
  if (!(*tmp))
    ret = exec_command(res);
  else if (*tmp == token_val(">") || *tmp == token_val(">>"))
    ret = parse_command_l_redir(res, 1);
  else
    ret = parse_command_r_redir(res, 2);
  free(res);
  return (ret);
}

