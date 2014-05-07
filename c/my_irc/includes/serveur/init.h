#ifndef		INIT_H_
# define	INIT_H_


/*
** PROTOTYPES
*/

void	accept_client(t_stck *s, int fd);
void	launch_serv(t_stck *s);
int	init(t_stck *s, int port);


#endif /* !INIT_H_ */
