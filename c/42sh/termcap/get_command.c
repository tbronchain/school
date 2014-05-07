#include <sys/ioctl.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "struct_termcap.h"
#include "init_struct.h"
#include "display_fcts.h"
#include "function_term.h"
#include "error.h"
#include "add_elem_to_list.h"
#include "list.h"
#include "del_element.h"
#include "sigwinch.h"
#include "xfunction_termcap_next.h"
#include "xfunction_termcap.h"
#include "my_env.h"
#include "get_command.h"
#include "utils.h"
#include "gere_key.h"

static int	restore(struct termios *oldline, t_list_recup_char *recup, int y)
{
  restore_mode(oldline);
  free_list(recup);
  y = 0;
  my_putchar('\n');
  return (y);
}

static void	refresh_line(t_term *term,
			     char *prompt,
			     t_list_recup_char *recup)
{
  int	tmp;

  term->x_winmax = xtgetnum("co");
  if (term->y > term->y_prompt)
    {
      tmp = term->y;
      while (tmp != term->y_prompt)
	{
	  xtputs(term->upstr, 1, my_outc);
	  tmp--;
	}
    }
  xtputs(term->crstr, 1, my_outc);
  xtputs(term->cdstr, 1, my_outc);
  my_putstr(prompt);
  my_put_list(recup);
}

static char		*launch_readline(t_term *term,
					 char *prompt,
					 struct termios *oldline)
{
  static int		y;
  t_list_recup_char	*recup;

  recup = NULL;
  xtputs(term->scstr, 1, my_outc);
  while (42)
    {
      refresh_line(term, prompt, recup);
      xtputs(term->rcstr, 1, my_outc);
      if ((term->cc = read(0, term->buf, sizeof (term->buf))) < 0)
	my_put_error("Error with read\n", 1);
      if (term->cc == 0)
	return (0);
      check_key(term, oldline, y, recup);
      if (term->flag == BSP)
	del_elem(&recup, &y, term);
      if (term->flag == 2)
	add_elem(&recup, &y, term);
      if (term->flag == ENT)
	{
	  y = restore(oldline, recup, y);
	  return (term->command);
	}
      xtputs(term->scstr, 1, my_outc);
    }
  return (0);
}

char			*get_command_termcap(char *prompt)
{
  struct termios	oldline;
  struct winsize	w;
  t_term		term;
  char			*command;

  if ((term.term = my_getenv("TERM")) == NULL)
    return (0);
  xtgetent(term.bp, term.term);
  sigwinch(&w);
  my_non_canonical_mode(&oldline);
  init_struct(&term, prompt);
  my_putstr(prompt);
  command = launch_readline(&term, prompt, &oldline);
  return (command);
}
