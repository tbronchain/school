#ifndef		UTILS_IA_H_
# define	UTILS_IA_H_

/*
** DEFINES
*/

#define HAUT		0
#define DROITE		1
#define BAS		2
#define GAUCHE		3

/*
** PROTOTYPES
*/

int	get_case_alloc_len(t_stck *s, t_view *v);
void	expulse_player(t_stck *s, int fd);
void	get_food(t_stck *s, int fd, int *val);
void	get_ressource_name(int type, t_view *v);
void	update_players_location(t_stck *s, int fd);

#endif /* !UTILS_IA_H_ */
