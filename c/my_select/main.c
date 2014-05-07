#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <stddef.h>

#include "my_select.h"

int	my_tcgetattr(int fd, struct termios *t);
int	my_tcsetattr(int fd, int opt, struct termios *t);
int	non_canonical_mode(struct termios *oldline);
int	restore_mode(struct termios *oldline, t_area *ar);
int	void_exit(t_area *ar, struct termios *oldline);
int	my_exit(struct termios *oldline, t_area *ar);
int	tputs(const char *str, int affcnt, int (*putc)(int));
int	tgetent(char *bp, const char *name);
int	tgetnum(char *id);
char	*tgetstr(char *id, char **area);

void	init_size(t_area *ar, char **argv)
{
  int	size;
  int	i;

  i = 0;
  ar->size = 0;
  while (i <= ar->ac)
    {
      size = my_strlen(argv[i]);
      if (size > ar->size)
	ar->size = size;
      i++;
    }
  ar->size++;
}

void	aff_list_resize(t_area *ar, int li, int co)
{
  ar->li = li;
  ar->co = co;
  ar->ac = make_argc(ar, ar->ac);
  tputs(ar->clstr, 1, my_outc);
  ar->x = 1;
  ar->y = 0;
  while (ar->y < ar->ac)
    {
      if (ar->res[ar->y] == 0)
	{
	  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
	  my_putstr(ar->av[(ar->y)++]);
	}
      else
	{
	  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
	  tputs(ar->sostr, 1, my_outc);
	  my_putstr(ar->av[(ar->y)++]);
	  tputs(ar->sestr, 1, my_outc);
	}
    }
  ar->x = 1;
  ar->y = 0;
  tputs(x_tgoto(ar->cmstr, ar->x, ar->y), 1, my_outc);
}

void			init_lines(t_area *ar, struct termios *oldline)
{
  struct winsize	w;
  int			li;
  int			co;

  if (ioctl(0, TIOCGWINSZ, &w) < 0)
    {
      restore_mode(oldline, ar);
      my_put_error(ERR_IOCTL);
      free_struct(ar);
      exit(EXIT_FAILURE);
    }
  li = w.ws_row;
  co = w.ws_col;
  if (li < 4 || co < ar->size)
    {
      restore_mode(oldline, ar);
      my_put_error(ERR_SIZE);
      free_struct(ar);
      exit(EXIT_FAILURE);
    }
  if (li != ar->li || co != ar->co)
    aff_list_resize(ar, li, co);
}

void		init_term(t_area *ar, char **argv, int argc)
{
  extern char	**environ;

  ar->term = cpy_from_env(environ, "TERM=");
  if (ar->term == NULL)
    {
      my_put_error(ERR_TERM);
      exit(EXIT_FAILURE);
    }
  x_tgetent(tgetent(ar->bp, ar->term));
  ar->area = ar->t;
  ar->clstr = xtgetstr("cl", &(ar->area));
  ar->cmstr = xtgetstr("cm", &(ar->area));
  ar->sostr = xtgetstr("so", &(ar->area));
  ar->sestr = xtgetstr("se", &(ar->area));
  ar->usstr = xtgetstr("us", &(ar->area));
  ar->uestr = xtgetstr("ue", &(ar->area));
  ar->li = tgetnum("li");
  ar->co = tgetnum("co");
  tputs(ar->clstr, 1, my_outc);
  argc = make_argc(ar, argc);
  ar->ac = argc - 1;
  ar->res = malloc(argc * sizeof(*(ar->res)));
  x_malloc(ar->res, argc);
  init_size(ar, argv);
  my_arg_cpy(ar, argv, argc);
}

int			main(int argc, char **argv)
{
  struct termios	oldline;
  t_area		ar;

  if (argc > 1)
    {
      non_canonical_mode(&oldline);
      init_term(&ar, argv, argc);
      display_arguments(&ar);
      while ((ar.len = read(0, ar.buff, sizeof(ar.buff))))
	{
	  x_read(ar.len);
	  init_lines(&ar, &oldline);
	  check_ctrl(&ar);
	  check_keys(&ar, ar.len);
	  check_select(&ar);
	  if (my_exit(&oldline, &ar) == 1 || void_exit(&ar, &oldline) == 1)
	    return (EXIT_SUCCESS);
	}
      restore_mode(&oldline, &ar);
      free_struct(&ar);
    }
  else
    my_put_error(ERR_ARGV);
  return (EXIT_SUCCESS);
}
