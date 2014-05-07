#include "struct_termcap.h"
#include "function_term.h"
#include "xfunction_termcap_next.h"
#include "gere_key_right.h"

static void	gere_key_right_one_line(t_term *term)
{
  term->x++;
  xtputs(term->ndstr, 1, my_outc);
  if (term->x > term->x_winmax + 1)
    {
      term->x = 0;
      term->y++;
      xtputs(term->crstr, 1, my_outc);
      xtputs(term->dostr, 1, my_outc);
    }
}

static void	gere_key_right_multi_line(t_term *term)
{
  term->x++;
  xtputs(term->ndstr, 1, my_outc);
  if (term->x > term->x_winmax)
    {
      term->x = 0;
      term->y++;
      xtputs(term->crstr, 1, my_outc);
      xtputs(term->dostr, 1, my_outc);
    }
}

void	gere_key_right(t_term *term)
{
  if (term->buf[0] == 27 && term->buf[1] == 91 && term->buf[2] == 67
      && term->cc == 3)
    {
      if (term->x < term->x_max)
	gere_key_right_one_line(term);
      else if (term->x >= term->x_max && term->y != term->y_max)
	gere_key_right_multi_line(term);
      else
        xtputs(term->blstr, 1, my_outc);
      term->flag++;
    }
}
