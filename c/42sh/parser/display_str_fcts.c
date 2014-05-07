#include <unistd.h>
#include "count_fcts.h"
#include "display_fcts.h"
#include "x_function_next.h"

void	my_putstr(char *str)
{
  while (*str)
    xwrite(1, &*str++, 1);
}
