#ifndef		SEND_H_
# define	SEND_H_


/*
** PROTOTYPES
*/

int	send_msg(char *msg, int fd, char *nick);
void	send_all(t_stck *s, char *msg, char *chan, char *nick);
void	send_oth(t_stck *s, int fd, char *msg, char *chan, char *nick);


#endif /* !SEND_H_ */
