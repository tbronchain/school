#include "init_struct.h"
#include "count_fcts.h"
#include "xfunction_termcap.h"

void	init_struct(t_term *term, char *prompt)
{
  term->area = term->t;
  term->x_prompt = my_strlen(prompt);
  term->x = term->x_prompt;
  term->x_max = term->x;
  term->y = 0;
  term->y_prompt = term->y;
  term->y_max = term->y;
  term->crstr = xtgetstr("cr", &term->area);
  term->cdstr = xtgetstr("cd", &term->area);
  term->clstr = xtgetstr("cl", &term->area);
  term->cmstr = xtgetstr("cm", &term->area);
  term->rcstr = xtgetstr("rc", &term->area);
  term->scstr = xtgetstr("sc", &term->area);
  term->blstr = xtgetstr("bl", &term->area);
  term->lestr = xtgetstr("le", &term->area);
  term->dostr = xtgetstr("do", &term->area);
  term->ndstr = xtgetstr("nd", &term->area);
  term->upstr = xtgetstr("up", &term->area);
}
