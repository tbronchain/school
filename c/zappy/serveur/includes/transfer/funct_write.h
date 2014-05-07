#ifndef		FUNCT_WRITE_H_
# define	FUNCT_WRITE_H_


/*
** PROTOTYPES
*/

int	funct_write(t_stck *s, int fd);
int	funct_dead(t_stck *s, int fd);
int	funct_kick(t_stck *s, int fd);
int	send_now(char *msg, t_stck *s, int fd);


#endif /* !FUNCT_WRITE_H_ */
