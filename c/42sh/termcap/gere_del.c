#include "struct_termcap.h"
#include "xfunction_termcap_next.h"
#include "utils.h"
#include "function_term.h"
#include "gere_backspace.h"
#include "gere_del.h"

void	gere_del(t_term *term)
{
  if (term->buf[0] == 27 && term->buf[1] == 91 && term->buf[2] == 51
      && term->buf[3] == 126 && term->cc == 4)
    {
      if (term->x != term->x_prompt)
	term->flag = BSP;
      else
        xtputs(term->blstr, 1, my_outc);
    }
}
