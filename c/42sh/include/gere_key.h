#ifndef GERE_KEY_H_
# define GERE_KEY_H_

#include <termios.h>
#include "struct_termcap.h"

/* define */
#define CTRLD 4

/* function */
void	check_key(t_term *term,
		  struct termios *oldline,
		  int y,
		  t_list_recup_char *recup);

#endif /* GERE_KEY_H_ */
