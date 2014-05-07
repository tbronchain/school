#ifndef		COORD_IA_H_
# define	COORD_IA_H_

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

int	*verif_coord(t_stck *s, t_view *v);
void	increment_coord_by_view(t_stck *s, int fd, t_view *v);
int	*get_player_view_case(t_stck *s, int fd, int level, int my_case);
int	*get_end_by_lvl(t_stck *s, int fd, int level, int *coord);

#endif /* !COORD_IA_H_ */
