#ifndef EVENT_ACTIONS_H_
# define EVENT_ACTIONS_H_


/*
** PROTOTYPES
*/

void	event_broadcast(t_stck *s, int fd, char *msg);
void	event_take(t_stck *s, int fd, int type);
void	event_drop(t_stck *s, int fd, int type);
void	event_expluse(t_stck *s, int fd, int *players);
void	event_incant(t_stck *s, int fd, int *players);
void	event_end_incant(t_stck *s, int fd, int *players, int flag);
void	event_end_incant_res(t_stck *s, int *move);
void	event_end_fork(t_stck *s, int fd, t_egg *new);
void	event_egg(t_stck *s, char *cmd, int id);


#endif /* !EVENT_ACTIONS_H_ */
