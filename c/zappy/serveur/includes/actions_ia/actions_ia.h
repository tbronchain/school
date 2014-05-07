#ifndef		ACTIONS_IA_H_
# define	ACTIONS_IA_H_

/*
** DEFINES
*/

enum {
  HAUT,
  DROITE,
  BAS,
  GAUCHE
};

/*
** PROTOTYPES
*/

int	make_view(t_stck *s, int fd);
int	move_left(t_stck *s, int fd);
int	move_right(t_stck *s, int fd);
int	move_forward(t_stck *s, int fd);
int	connect_nbr(t_stck *s, int fd);

#endif /* !ACTIONS_IA_H_ */
