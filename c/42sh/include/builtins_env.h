#ifndef BUILTINS_ENV_H__
# define BUILTINS_ENV_H__

#include "struct.h"

/* function */
int	built_setenv(char **arg);
int	built_unsetenv(char **arg);
int	built_env();

#endif /* BUILTINS_ENV_H_ */

