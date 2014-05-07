#ifndef LOGIC_PARSE_H__
# define LOGIC_PARSE_H__

#include "struct.h"

/* define */
#define ERR_CMD "Error : Invalid null command.\n"

/* struct */

typedef struct	s_logic_v
{
  t_logic	*lg;
  t_logic	*tmp;
  int		quit;
  int		skip;
  int		ret;
}		t_logic_v;

/* function */
int	logic_parse(char *command);

#endif /* LOGIC_PARSE_H_ */

