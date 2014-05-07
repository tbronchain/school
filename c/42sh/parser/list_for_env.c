#include <string.h>
#include <stdlib.h>
#include "count_fcts.h"
#include "modif_str_fcts.h"
#include "list_for_env.h"
#include "x_function.h"
#include "xfunction_termcap_next.h"
#include "error.h"

int	find_in_list_env(t_list *begin, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (begin != NULL && str[i] != '\0')
    {
      while (begin->data[i] != str[i] && str[i] != '\0'
	     && begin->data[i] != '\0')
        {
          i = 0;
          begin = begin->next;
          j++;
          if (begin == NULL)
            return (-1);
        }
      if (begin->data[i] == str[i])
        i++;
    }
  if (i == 0 || str[i] != '\0')
    return (-1);
  return (j);
}

int		my_put_in_list(t_list **begin, char *data)
{
  t_list	*new_elem;

  new_elem = xmalloc(sizeof(*new_elem));
  if (new_elem == NULL)
    {
      my_put_error("error", 0);
      exit(EXIT_FAILURE);
    }
  memset(new_elem, 0, sizeof(*new_elem));
  new_elem->data = data;
  new_elem->next = *begin;
  *begin = new_elem;
  return (0);
}

void	free_tab(char **tabs)
{
  int	size;
  int	i;

  i = 0;
  if (tabs != NULL)
    {
      while (tabs[i] != NULL)
        {
          size = my_strlen(tabs[i]);
          memset(tabs[i], 0, size);
          free(tabs[i++]);
        }
      free(tabs);
    }
}

int	my_put_in_tab(t_list *begin, char **sort)
{
  int	i;

  i = 0;
  while (begin != NULL)
    {
      sort[i] = x_malloc(sort[i], my_strlen(begin->data) + 1);
      my_strcpy(sort[i], begin->data);
      begin = begin->next;
      i++;
    }
  sort[i] = NULL;
  return (0);
}

void	my_list_tab_cpy(char **src, t_list **begin)
{
  char	*tmp;
  int	i;

  i = 0;
  while (src[i] != NULL)
    {
      tmp = x_malloc(tmp, strlen(src[i]) + 1);
      my_strcpy(tmp, src[i]);
      my_put_in_list(begin, tmp);
      i++;
    }
}
