#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"
#include "calc.h"
#include "my_lib.h"

static int	del_alloc_list(t_bd *to_add)
{
  t_bd		*tmp;

  if (gl_alloc == to_add)
    {
      gl_alloc = gl_alloc->next;
      if (gl_alloc)
	gl_alloc->prev = NULL;
      return (0);
    }
  tmp = gl_alloc;
  while (tmp)
    {
      if (tmp->next == to_add)
	break;
      tmp = tmp->next;
    }
  if (!tmp)
    return (-1);
  else if ((tmp->next = tmp->next->next))
    tmp->next->prev = tmp;
  return (0);
}

static void	insert_freelist(t_bd *to_add)
{
  t_bd		*tmp;
  int		i;

  i = to_add->p;
  tmp = buckets[i];
  buckets[i] = to_add;
  (buckets[i])->prev = NULL;
  (buckets[i])->next = tmp;
  if ((buckets[i])->next)
    (buckets[i])->next->prev = buckets[i];
}

void	free(void *ptr)
{
  char	*end;
  char	*to_add;

  init();
  if (!ptr)
    my_fputs("Warning: modified (chunk-) pointer\n", 2);
  else if (del_alloc_list((t_bd *)(to_add = (char *)ptr - SIZE_BD)))
    my_fputs("Warning: modified (chunk-) pointer\n", 2);
  else
    {
      end = (char *)(to_add + my_power(2, ((t_bd *)to_add)->p));
      if ((char *)sbrk(0) == (char *)end)
	if (sbrk(my_power(2, ((t_bd *)to_add)->p) * -1) != (void *)-1)
	  return ;
      insert_freelist((t_bd *)to_add);
    }
}
