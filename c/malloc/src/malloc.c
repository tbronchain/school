#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "calc.h"
#include "my_lib.h"

static void	*find_freeblock(unsigned int block_size)
{
  void		*ptr;
  t_bd		*save;
  int		pow;

  pow = get_power(block_size);
  if (buckets[pow])
    {
      save = buckets[pow];
      buckets[pow] = (buckets[pow])->next;
      if (buckets[pow])
	buckets[pow]->prev = NULL;
      return (save);
    }
  else if ((ptr = sbrk(block_size)) == (void *)-1)
    return (NULL);
  return (ptr);
}

static void	*init_malloc(size_t malloc_size)
{
  void		*adr_begin;
  t_bd		*tmp;
  unsigned int	block_size;

  malloc_size += SIZE_BD;
  if (!(block_size = get_block_size(malloc_size)))
    return (NULL);
  if (!(adr_begin = find_freeblock(block_size)))
    return (NULL);
  tmp = gl_alloc;
  gl_alloc = (t_bd *)adr_begin;
  gl_alloc->p = get_power(block_size);
  gl_alloc->next = tmp;
  gl_alloc->prev = NULL;
  if (gl_alloc->next)
    gl_alloc->next->prev = gl_alloc;
  return ((void *)((char *)adr_begin + SIZE_BD));
}

void	*malloc(size_t malloc_size)
{
  void	*p;

  init();
  if ((int)malloc_size < 0)
    return (NULL);
  else if (malloc_size == 0)
    return ((void *)0x800);
  p = init_malloc(malloc_size);
  return (p);
}
