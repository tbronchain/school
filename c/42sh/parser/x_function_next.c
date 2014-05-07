#include <unistd.h>
#include "error.h"
#include "x_function_next.h"

void	xwrite(int fd, char *str, int len)
{
  int	x;

  x = write(fd, str, len);
  if (x == -1)
    my_put_error("Error with read\n", 0);
}

int	xwaitpid(pid_t wpid, int *status, int options)
{
  if (waitpid(wpid, status, options) == -1)
    return (1);
  return (0);
}

int	xopen(char *file, int flag, mode_t mode)
{
  int	fd;

  fd = open(file, flag, mode);
  if (fd < 1)
    my_put_error("Error with open\n", 0);
  return (fd);
}

int	xdup2(int old, int new)
{
  int	ret;

  ret = 0;
  ret = dup2(old, new);
  if (ret == - 1)
    my_put_error("Error with dup2\n", 0);
  return (ret);
}

int	xdup(int old)
{
  int	ret;

  ret = 0;
  ret = dup(old);
  if (ret == - 1)
    my_put_error("Error with dup\n", 0);
  return (ret);
}
