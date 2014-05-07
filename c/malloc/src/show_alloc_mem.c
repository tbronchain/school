#include <unistd.h>
#include "struct.h"
#include "calc.h"
#include "my_lib.h"

void	*sbrk(int increment);

void	show_alloc_mem()
{
  t_bd	*tmp;

  tmp = gl_alloc;
  my_fputs("break : 0x", 1);
  my_put_hexa((unsigned int)(char *)sbrk(0));
  my_fputs("\n", 1);
  if (tmp != NULL)
    while (tmp->next != NULL)
      tmp = tmp->next;
  while (tmp)
    {
      my_fputs("0x", 1);
      my_put_hexa((int)tmp + SIZE_BD);
      my_fputs(" - 0x", 1);
      my_put_hexa((int)tmp + SIZE_BD + my_power(2, tmp->p));
      my_fputs(" : ", 1);
      my_put_nbr(my_power(2, tmp->p));
      my_fputs(" octets\n", 1);
      tmp = tmp->prev;
    }
}

void	show_free_mem()
{
  t_bd	*tmp;
  int	i;

  i = -1;
  my_fputs("break : 0x", 1);
  my_put_hexa((int)sbrk(0));
  my_fputs("\n", 1);
  while (++i < 32)
    {
      tmp = buckets[i];
      if (tmp != NULL)
	while (tmp->next != NULL)
	  tmp = tmp->next;
      while (tmp)
	{
	  my_fputs("0x", 1);
	  my_put_hexa((int)tmp + SIZE_BD);
	  my_fputs(" - 0x", 1);
	  my_put_hexa((int)tmp + SIZE_BD + my_power(2, tmp->p));
	  my_fputs(" : ", 1);
	  my_put_nbr(my_power(2, tmp->p));
	  my_fputs(" octets\n", 1);
	  tmp = tmp->prev;
	}
    }
}
