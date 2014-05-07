#include <stdlib.h>
#include "struct.h"
#include "token.h"
#include "check_redir.h"
#include "make_redir.h"
#include "parse_redir.h"
#include "x_function_next.h"
#include "x_function.h"

extern t_pipe gl_pipe[];

void	make_free(char *name)
{
  if (name && name != (char *) - 1)
    free(name);
}

int	parse_command_r_redir(char *command, int opt)
{
  char	*name;
  int	ret;
  int	fd;
  int	mask;

  mask = get_mask(command);
  name = check_name(&command);
  ret = 1;
  if (name && name != (char *) - 1)
    {
      fd = xopen(name, mask, 0600);
      if ((mask = xdup(1)) < 0)
        return (1);
      if (xdup2(fd, 1) < 0)
        return (1);
      ret = gl_pipe[opt].fct(command, 0);
      if (xdup2(mask, 1) < 0)
        return (1);
      xclose(fd);
      xclose(mask);
    }
  else if (!name)
    ret = gl_pipe[opt].fct(command, 0);
  make_free(name);
  return (ret);
}

int	parse_command_l_redir(char *command, int opt)
{
  char	*name;
  int	tmp;
  int	ret;
  int	fd;

  name = go_after(&command, token_val("<"));
  ret = 1;
  if (name && name != (char *) - 1)
    {
      if ((fd = xopen(name, O_RDONLY, 0600)) < 1)
	return (1);
      if ((tmp = xdup(0)) < 0)
	return (1);
      if (xdup2(fd, 0) < 0)
	return (1);
      ret = gl_pipe[opt].fct(command, 0);
      xclose(fd);
      if (xdup2(tmp, 0) < 0)
	return (1);
      xclose(tmp);
    }
  else if (!name)
    ret = gl_pipe[opt].fct(command, 0);
  make_free(name);
  return (ret);
}
