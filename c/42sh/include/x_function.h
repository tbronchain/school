#ifndef X_FUNCTION_H__
# define X_FUNCTION_H__

/* function */
int	xpipe(int *p);
void	*xrealloc(void *ptr, int size);
void	*xmalloc(int size);
int	xfork();
int	xclose(int fd);

#endif /* X_FUNCTION_H_ */

