#ifndef FUNCTION_TERM_H_
# define FUNCTION_TERM_H_

#include <termios.h>

#ifndef TIOCGETA
# define TIOCGETA TCGETS
#endif

#ifndef TIOCSETA
# define TIOCSETA TCSETS
#endif

#ifndef TIOCGWINSZ
# define TIOCGWINSZ TIOCGSIZE
#endif

#ifndef TCSASOFT
# define TCSASOFT 0
#endif

#ifndef CIGNORE
# define CIGNORE 0
#endif

#ifndef TIOCSETAW
# define TIOCSETAW 0
#endif

#ifndef TIOCSETAF
# define TIOCSETAF 0
#endif

/*function*/
int	my_outc(int c);
void	my_bytecopy(const void *src, void *dest, int size);
int	restore_mode(struct termios *oldline);
int	my_non_canonical_mode(struct termios *oldline);

#endif /* FUNCTION_TERM_H_ */
