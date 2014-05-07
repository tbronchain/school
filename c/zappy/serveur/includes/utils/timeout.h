#ifndef		TIMEOUT_H_
# define	TIMEOUT_H_


/*
** PROTOTYPES
*/

int		set_timeout(t_stck *s, int fd, int pause, int (*funct_wait)());
void		exec_timeout(t_stck *s);
struct timeval	*check_timeout(t_stck *s, struct timeval *tv, int flag);


#endif /* !TIMEOUT_H_ */
