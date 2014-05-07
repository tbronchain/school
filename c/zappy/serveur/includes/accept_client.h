#ifndef		ACCEPT_CLIENT_H_
# define	ACCEPT_CLIENT_H_


/*
** DEFINES
*/

#define ID_MAX_SIZE	2000000000


/*
** PROTOTYPES
*/

int	select_client(t_stck *s, int fd, char *cmd);
int	accept_client(t_stck *s, int fd);


#endif /* !ACCEPT_CLIENT_H_ */
