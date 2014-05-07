#include <stdlib.h>
#include "struct_termcap.h"
#include "del_element.h"
#include "xfunction_termcap_next.h"
#include "function_term.h"

static t_list_recup_char	*del_element_in_line(t_list_recup_char *list,
						     int *y)
{
  t_list_recup_char		*elem;

  if (list->back)
    list = list->back;
  if (list->back)
    list->back->next = list->next;
  if (list->next)
    list->next->back = list->back;
  if (list->back)
    elem = list->back;
  else
    elem = list->next;
  free(list);
  (*y)--;
  return (elem);
}

static t_list_recup_char	*del_element_at_end(t_list_recup_char *list,
						    int *y)
{
  t_list_recup_char		*elem;

  if (list->back)
    list->back->next = list->next;
  if (list->next)
    list->next->back = list->back;
  if (list->back)
    elem = list->back;
  else
    elem = list->next;
  free(list);
  (*y)--;
  return (elem);
}

static void	preparation_to_del(t_list_recup_char **recup,
				   t_term *term)
{
  int	i;
  int	x;

  i = term->x_prompt;
  x = term->y_prompt;
  while ((*recup)->back)
    (*recup) = (*recup)->back;
  while (x != term->y)
    {
      while (i < term->x_winmax)
	{
	  (*recup) = (*recup)->next;
	  i++;
	}
      i = 0;
      x++;
    }
  while (i < term->x)
    {
      (*recup) = (*recup)->next;
      i++;
    }
}

static void	del_else(t_list_recup_char **recup, t_term *term)
{
  int		i;

  i = term->x_prompt;
  while ((*recup)->back)
    (*recup) = (*recup)->back;
  while (i != term->x)
    {
      (*recup) = (*recup)->next;
      i++;
    }
}

void	del_elem(t_list_recup_char **recup, int *y, t_term *term)
{
  if (term->x == term->x_max)
    {
      while ((*recup)->back)
	(*recup) = (*recup)->back;
      while ((*recup)->next)
	(*recup) = (*recup)->next;
      (*recup) = del_element_at_end((*recup), y);
    }
  else
    {
      if (term->y > term->y_prompt)
	preparation_to_del(recup, term);
      else
	del_else(recup, term);
      (*recup) = del_element_in_line((*recup), y);
    }
  term->x--;
  term->x_max--;
  xtputs(term->lestr, 1, my_outc);
}
