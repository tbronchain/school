#ifndef		INIT_H_
# define	INIT_H_


/*
** DEFINES
*/

# ifndef	SO_NOSIGPIPE
#  define	SO_NOSIGPIPE	0
# endif


/*
** PROTOTYPES
*/

void	init(t_stck *s);
int	end(t_stck *s, int val);


#endif /* !INIT_H_ */
