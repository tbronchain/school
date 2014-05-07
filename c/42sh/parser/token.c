#include <string.h>
#include "struct.h"
#include "token.h"

extern t_token	gl_token[];

char	token_valid(char to_test)
{
  int	i;

  i = 0;
  while (gl_token[i].token && gl_token[i].val != to_test)
    i++;
  if (gl_token[i].token)
    return (gl_token[i].valid_sep);
  return (0);
}

char	token_val(char *str)
{
  int	i;

  i = 0;
  while (gl_token[i].token
	 && strncmp(gl_token[i].token, str, gl_token[i].len))
    i++;
  if (gl_token[i].token)
    return (gl_token[i].val);
  return (0);
}

int	check_token(char *str)
{
  int	i;

  i = 0;
  while (gl_token[i].token
	 && strncmp(gl_token[i].token, str, gl_token[i].len))
    i++;
  if (gl_token[i].token)
    return (i);
  return (-1);
}

void	gere_token(char **str, int i)
{
  char	*tmp;
  int	j;

  tmp = *str;
  *tmp = gl_token[i].val;
  if (gl_token[i].len > 1)
    {
      tmp++;
      j = 0;
      while (tmp[j + 1])
	{
	  tmp[j] = tmp[j + 1];
	  j++;
	}
      tmp[j] = 0;
      tmp--;
    }
  *str = tmp;
}

