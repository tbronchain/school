#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils/x.h"

void	*x(void *err, void *res, char *str, char *file, int line)
{
  if (res == err)
    {
      fprintf(stderr, "Error with %s (in %s, line %d): %s\n",
	      str, file, line, strerror(errno));
      _exit(EXIT_FAILURE);
    }
  return (res);
}

void	*_x(void *err, void *res, char *str, char *file, int line)
{
  if (res == err)
    fprintf(stderr, "Error with %s (in %s, line %d): %s\n",
	    str, file, line, strerror(errno));
  return (res);
}

void	*xmalloc(int size, char *file, int line)
{
  void	*p;

  if (!(p = malloc(size)))
    {
      fprintf(stderr, "Can't alloc memory() (in %s, line %d) : %s\n",
	      file, line, strerror(errno));
      _exit(EXIT_FAILURE);
    }
  memset(p, 0, size);
  return (p);
}
