#ifndef X_FUNCTION_NEXT_H__
# define X_FUNCTION_NEXT_H__

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

/* function */
int	xdup(int old);
int	xdup2(int old, int new);
int	xopen(char *file, int flag, mode_t mode);
int	xwaitpid(pid_t wpid, int *status, int options);
void	xwrite(int fd, char *str, int len);

#endif /* X_FUNCTION_NEXT_H_ */

