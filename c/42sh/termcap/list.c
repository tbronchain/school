#include <stdlib.h>
#include "utils.h"
#include "list.h"

void	my_put_list(t_list_recup_char *elem)
{
  if (elem != NULL)
    {
      while (elem->back != NULL)
	elem = elem->back;
      while (elem != NULL)
	{
	  my_putchar(elem->c);
	  elem = elem->next;
	}
    }
}

int	listlen(t_list_recup_char *list)
{
  int	size;

  size = 0;
  if (list)
    {
      while (list->back)
	list = list->back;
      while (list)
	{
	  list = list->next;
	  size++;
	}
    }
  return (size);
}

void			free_list(t_list_recup_char *elem)
{
  t_list_recup_char	*actualelem;
  t_list_recup_char	*tmp;

  if (elem != NULL)
    {
      actualelem = elem;
      while (actualelem->back != NULL)
        actualelem = actualelem->back;
      while (actualelem->next != NULL)
        {
          tmp = actualelem->next;
          free(actualelem);
          actualelem = tmp;
        }
      free(actualelem);
    }
}
