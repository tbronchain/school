#include "struct_termcap.h"
#include "function_term.h"
#include "xfunction_termcap_next.h"
#include "utils.h"
#include "gere_end.h"

static void	gere_end_multi_line(t_term *term)
{
  int	tmp;

  tmp = term->y;
  while (tmp != term->y_max)
    {
      tmp++;
      xtputs(term->dostr, 1, my_outc);
    }
  term->y = term->y_max;
  tmp = term->x;
  term->x = term->x_max;
  while (tmp != term->x_max)
    {
      if (tmp < term->x)
	{
	  tmp++;
	  xtputs(term->ndstr, 1, my_outc);
	}
      else
	{
	  tmp--;
	  xtputs(term->lestr, 1, my_outc);
	}
    }
}

void	gere_end(t_term *term)
{
  int	tmp;

  if (term->buf[0] == 27 && term->buf[1] == 91 && term->buf[2] == 70
      && term->cc == 3)
    {
      if (term->x != term->x_max)
        {
          tmp = term->x;
          if (term->y == term->y_max)
            {
              term->x = term->x_max;
              while (tmp < term->x_max)
                {
                  xtputs(term->ndstr, 1, my_outc);
                  tmp++;
                }
            }
          else
	    gere_end_multi_line(term);
        }
      else
        xtputs(term->blstr, 1, my_outc);
      term->flag++;
    }
}
