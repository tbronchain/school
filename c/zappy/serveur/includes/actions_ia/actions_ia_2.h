#ifndef		ACTIONS_IA_2_H_
# define	ACTIONS_IA_2_H_

/*
** PROTOTYPES
*/

int	get_invent(t_stck *s, int fd);
int	make_expulse(t_stck *s, int fd);
int	take_object(t_stck *s, int fd, t_wait *t);
int	drop_object(t_stck *s, int fd, t_wait *t);
int	broadcast(t_stck *s, int fd, t_wait *t);

#endif /* !ACTIONS_IA_2_H_ */
