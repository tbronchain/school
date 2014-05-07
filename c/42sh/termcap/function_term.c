#include "function_term.h"
#include "utils.h"
#include "error.h"
#include "xfunction_termcap.h"

int			my_outc(int c)
{
  my_putchar(c);
  return (0);
}

void			my_bytecopy(const void *src, void *dest, int size)
{
  const char		*src2;
  char			*dest2;
  int			i;

  src2 = src;
  dest2 = dest;
  i = size;
  if (src2 < dest2)
    while (i)
      {
        dest2[i] = src2[i];
        i--;
      }
  else if (src2 > dest2)
    {
      i = 0;
      while (i != size)
        {
          dest2[i] = src2[i];
          i++;
        }
    }
}

int			restore_mode(struct termios *oldline)
{
  if (xtcsetattr(0, TCSANOW, oldline) < 0)
    my_put_error("Error with tcsetattr\n", 1);
  return (0);
}

int			my_non_canonical_mode(struct termios *oldline)
{
  struct termios	line;

  if (xtcgetattr(0, oldline) < 0)
    my_put_error("Error with tcgetattr\n", 1);
  my_bytecopy(oldline, &line, sizeof (line));
  line.c_lflag &= ~(ICANON | ECHO);
  line.c_cc[VMIN] = 1;
  line.c_cc[VTIME] = 0;
  if (xtcsetattr(0, TCSANOW, &line) < 0)
    my_put_error("Error with tcsetattr\n", 1);
  return (0);
}
