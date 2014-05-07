#ifndef		BAN_H_
# define	BAN_H_


/*
** PROTOTYPES
*/

int	check_ban(t_ban **ban, char *ip, int fd);
void	ban(t_ban **ban, char *ip, int fd);


#endif /* !BAN_H_ */
