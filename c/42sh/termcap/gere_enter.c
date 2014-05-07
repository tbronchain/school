#include <unistd.h>
#include "struct_termcap.h"
#include "gere_enter.h"
#include "list.h"
#include "utils.h"
#include "display_fcts.h"
#include "xfunction_termcap_next.h"

static void	list_to_str(t_term *term, t_list_recup_char *recup, int size)
{
  int	i;

  i = 0;
  term->command = my_xmalloc(term->command, size + 1);
  while (recup->back)
    recup = recup->back;
  while (recup)
    {
      term->command[i] = recup->c;
      i++;
      recup = recup->next;
    }
}

void	gere_enter(t_term *term, t_list_recup_char *recup)
{
  int	size;

  if (term->buf[0] == ENT && term->cc == 1)
    {
      size = listlen(recup);
      if (size != 0)
        {
          if (size < 255)
	    list_to_str(term, recup, size);
	  else
	    {
	      my_putstr("\nLine too long");
	      term->command = NULL;
	    }
	}
      else
	term->command = NULL;
      term->flag = ENT;
    }
}
