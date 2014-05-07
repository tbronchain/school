#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct_termcap.h"
#include "function_term.h"
#include "error.h"
#include "xfunction_termcap.h"

int			xtcgetattr(int fd, struct termios *term)
{
  int			var;

  if ((var = ioctl(fd, TIOCGETA, term)) == -1)
    my_put_error("Error with tcgetattr\n", 1);
  return (var);
}

int			xtcsetattr(int fd, int opt, struct termios *term)
{
  struct termios	l;

  my_bytecopy((char *)term, (char *)&l, sizeof (struct termios));
  if (opt & TCSASOFT)
    l.c_cflag |= CIGNORE;
  if ((opt & ~TCSASOFT) == TCSANOW)
    return (ioctl(fd, TIOCSETA, &l));
  else if ((opt & ~TCSASOFT) == TCSADRAIN)
    return (ioctl(fd, TIOCSETAW, &l));
  else if ((opt & ~TCSASOFT) == TCSAFLUSH)
    return (ioctl(fd, TIOCSETAF, &l));
  else
    return (-1);
  return (0);
}

int			xtgetnum(char *id)
{
  int			num;

  if ((num = tgetnum(id)) < 0)
    my_put_error("Error with tgetnum\n", 1);
  return (num);
}

char			*xtgetstr(char *cap, char **area)
{
  char			*capstr;

  if ((capstr = tgetstr(cap, area)) == NULL)
    {
      my_put_error("problem getting ", 1);
      my_put_error(cap, 0);
      my_put_error("\n", 1);
    }
  return (capstr);
}

int			xtgetent(char *bp, char *name)
{
  int			var;

  var = tgetent(bp, name);
  if (var != 1)
    my_put_error("Problem with tgetent\n", 1);
  return (var);
}
