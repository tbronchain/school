#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "count_fcts.h"
#include "x_function_next.h"

int	my_put_error(char *err, int quit)
{
  int	i;

  i = 0;
  while (err[i] != '\0')
    {
      xwrite(2, &err[i], 1);
      i++;
    }
  if (quit == 1)
    _exit(EXIT_FAILURE);
  return (1);
}
