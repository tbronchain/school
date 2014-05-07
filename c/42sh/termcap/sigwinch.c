#include <sys/ioctl.h>
#include <unistd.h>
#include "sigwinch.h"
#include "error.h"
#include "function_term.h"

void		sigwinch(struct winsize *w)
{
  if (ioctl(0, TIOCGWINSZ, w) < 0)
    my_put_error("error with ioctl\n", 1);
}
