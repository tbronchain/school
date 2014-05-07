#ifndef		X_H_
# define	X_H_


/*
** PROTOTYPES
*/

void	*x(void *err, void *res, char *str, char *file, int line);
void	*_x(void *err, void *res, char *str, char *file, int line);
void	*xmalloc(int size, char *file, int line);
int	null(void *p);


/*
** MACRO
*/

#define _X(err, res, str)	(_x(err, res, str, __FILE__, __LINE__))
#define X(err, res, str)	(x(err, res, str, __FILE__, __LINE__))
#define Xmalloc(size)		(xmalloc(size, __FILE__, __LINE__))


#endif /* !X_H_ */
