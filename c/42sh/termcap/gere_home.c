#include "struct_termcap.h"
#include "function_term.h"
#include "xfunction_termcap_next.h"
#include "gere_home.h"

static void	gere_home_one_line(t_term *term)
{
  int	tmp;

  tmp = term->x;
  term->x = term->x_prompt;
  while (tmp != term->x_prompt)
    {
      xtputs(term->lestr, 1, my_outc);
      tmp--;
    }
}

static void	gere_home_multi_line(t_term *term)
{
  int	tmp;

  tmp = term->y;
  while (tmp != 0)
    {
      tmp--;
      xtputs(term->upstr, 1, my_outc);
    }
  term->y = term->y_prompt;
  tmp = term->x;
  term->x = term->x_prompt;
  while (tmp != term->x_prompt)
    {
      if (tmp < term->x)
	{
	  xtputs(term->ndstr, 1, my_outc);
	  tmp++;
	}
      else
	{
	  xtputs(term->lestr, 1, my_outc);
	  tmp--;
	}
    }
}

void	gere_home(t_term *term)
{
  if (term->buf[0] == 27 && term->buf[1] == 91
      && term->buf[2] == 72 && term->cc == 3)
    {
      if (term->x != term->x_prompt && term->y == 0)
	gere_home_one_line(term);
      else if (term->y != 0)
	gere_home_multi_line(term);
      else
        xtputs(term->blstr, 1, my_outc);
      term->flag++;
    }
}
