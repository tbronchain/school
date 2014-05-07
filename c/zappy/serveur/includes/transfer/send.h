#ifndef		SEND_H_
# define	SEND_H_


/*
** PROTOTYPES
*/

int	send_one(char *msg, int fd, t_stck *s);
int	send_graphic(char *msg, t_stck *s);
int	send_all(t_stck *s, char *msg, int type1, int type2);
int	send_split(char *buf, int fd);
int	send_ko(t_stck *s, int fd);


#endif /* !SEND_H_ */
