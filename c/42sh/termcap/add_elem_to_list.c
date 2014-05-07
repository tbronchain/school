#include <stdlib.h>
#include "function_term.h"
#include "x_function.h"
#include "xfunction_termcap_next.h"
#include "add_elem_to_list.h"

static t_list_recup_char	*new_element_at_end(t_list_recup_char *previouselem,
						    int *size_list,
						    char buf)
{
  t_list_recup_char		*newelem;

  newelem = xmalloc(sizeof(*newelem));
  newelem->back = previouselem;
  newelem->next = NULL;
  newelem->c = buf;
  if (*size_list != 0)
    previouselem->next = newelem;
  previouselem = newelem;
  *size_list = *size_list + 1;
  return (previouselem);
}

static t_list_recup_char	*insert_element_in_line(t_list_recup_char *previouselem,
							int *size_list,
							char buf)
{
  t_list_recup_char		*newelem;

  newelem = xmalloc(sizeof (*newelem));
  newelem->next = previouselem;
  if (previouselem->back == NULL)
    newelem->back = NULL;
  else
    {
      newelem->back = previouselem->back;
      previouselem->back->next = newelem;
    }
  previouselem->back = newelem;
  newelem->c = buf;
  *size_list = *size_list + 1;
  return (previouselem);
}

static void			preparation_to_insert(t_list_recup_char **previouselem,
						      t_term *term,
						      int *i,
						      int *y)
{
  if (term->y > term->y_prompt)
    {
      (*y) = term->y_prompt;
      while ((*y) != term->y)
	{
	  while ((*i) < term->x_winmax)
	    {
	      (*previouselem) = (*previouselem)->next;
	      (*i)++;
	    }
	  (*i) = 0;
	  (*y)++;
	}
      while ((*i) < term->x)
	{
	  (*previouselem) = (*previouselem)->next;
	  (*i)++;
	}
    }
  if (term->x > term->x_prompt && term->y == term->y_prompt)
    while ((*i) < term->x)
      {
	(*previouselem) = (*previouselem)->next;
	(*i)++;
      }
}

static t_list_recup_char	*add_element_to_list(t_list_recup_char *previouselem,
						     int *size_list,
						     char buf,
						     t_term *term)
{
  int				i;
  int				y;

  i = term->x_prompt;
  if (term->x == term->x_max)
    {
      if (*size_list == 0)
	previouselem = new_element_at_end(previouselem, size_list, buf);
      else
	{
	  while (previouselem->next != NULL)
	    previouselem = previouselem->next;
	  previouselem = new_element_at_end(previouselem, size_list, buf);
	}
    }
  else
    {
      while (previouselem->back != NULL)
	previouselem = previouselem->back;
      preparation_to_insert(&previouselem, term, &i, &y);
      previouselem = insert_element_in_line(previouselem, size_list, buf);
    }
  return (previouselem);
}

void				add_elem(t_list_recup_char **list,
					 int *y,
					 t_term *term)
{
  *list = add_element_to_list(*list, y, term->buf[0], term);
  if (term->x == term->x_winmax)
    {
      term->x = 0;
      term->x_max = term->x;
      term->y++;
      term->y_max++;
      xtputs(term->crstr, 1, my_outc);
      xtputs(term->dostr, 1, my_outc);
    }
  xtputs(term->ndstr, 1, my_outc);
  term->x++;
  term->x_max++;
}
