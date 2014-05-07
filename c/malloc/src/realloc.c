#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "calc.h"
#include "free.h"
#include "malloc.h"
#include "my_lib.h"

static void	my_memcpy(void *dest, void *src, int size)
{
  char		*dest2;
  char		*src2;
  int		i;

  i = 0;
  dest2 = (char *)dest;
  src2 = (char *)src;
  while (i < size)
    {
      dest2[i] = src2[i];
      i++;
    }
}

static void	*init_realloc(void *ptr, int size, int old_size, int flag)
{
  void		*ptr2;

  ptr = (void *)((char *)ptr + SIZE_BD);
  if (!(ptr2 = malloc(size)))
    return (NULL);
  if (flag == 0)
    my_memcpy(ptr2, ptr, old_size);
  else if (flag == 1)
    my_memcpy(ptr2, ptr, size);
  free(ptr);
  return (ptr2);
}

static void	*find_alloc(void *ptr, int p, int old_p, int size)
{
  if (old_p == p)
    return ((void *)((char *)ptr + SIZE_BD));
  else if (old_p > p)
    return (init_realloc(ptr, size, my_power(2, old_p), 1));
  return (init_realloc(ptr, size, my_power(2, old_p), 0));
}

static void	*find_in_alloc_list(void *ptr)
{
  t_bd		*tmp;

  tmp = gl_alloc;
  while (tmp)
    {
      if (tmp == (t_bd *)ptr)
	return (ptr);
      tmp = tmp->next;
    }
  return (NULL);
}

void	*realloc(void *ptr, size_t realloc_size)
{
  int	size;
  int	p;

  init();
  if (!ptr)
    return (malloc(realloc_size));
  else if (!find_in_alloc_list((void *)((char *)ptr - SIZE_BD)))
    return (malloc(realloc_size));
  else if (realloc_size == 0)
    {
      free(ptr);
      return (NULL);
    }
  ptr = (void *)((char *)ptr - SIZE_BD);
  realloc_size += SIZE_BD;
  size = get_block_size(realloc_size);
  p = get_power(size);
  return (find_alloc(ptr, p, ((t_bd *)ptr)->p, size));
}
