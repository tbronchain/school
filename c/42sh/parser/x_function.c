#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "x_function.h"
#include "error.h"

int	xfork()
{
  int	ret;

  ret = 0;
  ret = fork();
  if (ret == - 1)
    my_put_error("Error with fork.\n", 0);
  return (ret);
}

int	xclose(int fd)
{
  int	ret;

  ret = 0;
  ret = close(fd);
  if (ret == - 1)
    my_put_error("Error with close.\n", 0);
  return (ret);
}

int	xpipe(int *p)
{
  if (pipe(p) < 0)
    {
      return (0);
      my_put_error("Error with pipe.\n", 0);
    }
  return (1);
}

void	*xrealloc(void *ptr, int size)
{
  void	*tmp;

  if (!(tmp = realloc(ptr, size)))
    my_put_error("Error with realloc.\n", 0);
  return (tmp);
}

void	*xmalloc(int size)
{
  void	*tmp;

  if (!(tmp = malloc(size)))
    my_put_error("Error with malloc.\n", 0);
  memset(tmp, 0, size);
  return (tmp);
}
