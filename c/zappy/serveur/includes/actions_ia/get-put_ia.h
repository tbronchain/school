#ifndef		GET_PUT_IA_H_
# define	GET_PUT_IA_H_

/*
** PROTOTYPES
*/

void	get_invent_case(t_stck *s, int fd, char *invent, char *tmp);
void	update_death_timer(t_stck *s, int fd, int flag);
int	get_object_name(char *cmd);

#endif /* !GET_PUT_IA_H_ */
