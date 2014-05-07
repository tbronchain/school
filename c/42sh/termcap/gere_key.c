#include <stdlib.h>
#include <unistd.h>
#include "gere_key.h"
#include "utils.h"
#include "struct_termcap.h"
#include "display_fcts.h"
#include "del_element.h"
#include "function_term.h"
#include "xfunction_termcap_next.h"
#include "list.h"
#include "gere_del.h"
#include "gere_end.h"
#include "gere_home.h"
#include "gere_backspace.h"
#include "gere_enter.h"
#include "gere_key_right.h"
#include "gere_key_left.h"

void	check_key(t_term *term,
		  struct termios *oldline,
		  int y,
		  t_list_recup_char *recup)
{
  term->flag = 0;
  gere_key_right(term);
  gere_key_left(term);
  gere_del(term);
  gere_end(term);
  gere_home(term);
  gere_backspace(term);
  gere_enter(term, recup);
  if ((term->buf[0] == CTRLD) && (term->cc == 1))
    {
      restore_mode(oldline);
      free_list(recup);
      y = 0;
      my_putstr("exit\n");
      _exit(EXIT_SUCCESS);
    }
  if ((term->flag == 0) && ((my_str_isprintable(term->buf) == 1)))
    term->flag = 2;
}
