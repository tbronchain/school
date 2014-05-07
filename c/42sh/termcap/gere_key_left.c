#include "struct_termcap.h"
#include "function_term.h"
#include "gere_key_left.h"
#include "xfunction_termcap_next.h"

static void	gere_key_left_multi_line(t_term *term)
{
  int	tmp;

  term->x--;
  if (term->x < 0)
    {
      term->y--;
      tmp = term->x;
      term->x = term->x_winmax;
      while (tmp <= term->x_winmax)
	{
	  xtputs(term->ndstr, 1, my_outc);
	  tmp++;
	}
      xtputs(term->upstr, 1, my_outc);
    }
  xtputs(term->lestr, 1, my_outc);
}

void	gere_key_left(t_term *term)
{
  if (term->buf[0] == 27 && term->buf[1] == 91
      && term->buf[2] == 68 && term->cc == 3)
    {
      if (term->x > term->x_prompt && term->y == 0)
        {
          term->x--;
          xtputs(term->lestr, 1, my_outc);
        }
      else if (term->y != term->y_prompt)
	gere_key_left_multi_line(term);
      else
        xtputs(term->blstr, 1, my_outc);
      term->flag++;
    }
}
