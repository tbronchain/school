#ifndef XFUNCTION_TERMCAP_H_
# define XFUNCTION_TERMCAP_H_

#include <termios.h>

/* system definitions */

int	tgetnum(char *id);
char	*tgetstr(char *id, char **area);
int	tgetent(char *bp, const char *name);
int	tputs(const char *str, int affcnt, int (*putc)(int));

/* function.h */
int	xtcgetattr(int fd, struct termios *term);
int	xtcsetattr(int fd, int opt, struct termios *term);
int	xtgetnum(char *id);
char	*xtgetstr(char *cap, char **area);
int	xtgetent(char *bp, char *name);

#endif /* XFUNCTION_TERMCAP_H_ */
