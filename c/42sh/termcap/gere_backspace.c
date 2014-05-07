#include "struct_termcap.h"
#include "function_term.h"
#include "gere_backspace.h"
#include "xfunction_termcap_next.h"

void	gere_backspace(t_term *term)
{
  int	i;

  i = 0;
  if (term->buf[0] == BSP && term->cc == 1)
    {
      if (term->x  != term->x_prompt)
	  term->flag = BSP;
      else
	xtputs(term->blstr, 1, my_outc);
    }
}
