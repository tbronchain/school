#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "error.h"

void	free_del_elem(t_list **begin, void *save, void *tmp, int count)
{
  int	i;

  i = 0;
  if (count == 0)
    {
      free((*begin)->data);
      *begin = (*begin)->next;
      free(save);
    }
  else
    {
      *begin = save;
      while (i < (count - 1))
        {
          *begin = (*begin)->next;
          i++;
        }
      free((*begin)->next->data);
      (*begin)->next = (*begin)->next->next;
      free(tmp);
      *begin = save;
    }
}

int	del_elems(t_list **begin, char *data)
{
  void	*tmp;
  void	*save;
  int	count;

  save = *begin;
  count = 0;
  while (strcmp(data, (*begin)->data) != 0)
    {
      *begin = (*begin)->next;
      count++;
      if ((*begin)->data == NULL)
        {
          my_put_error("unsetenv: sorry, not in environnement.\n", 0);
          return (-1);
        }
    }
  tmp = *begin;
  free_del_elem(begin, save, tmp, count);
  return (0);
}
