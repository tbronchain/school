#ifndef		INCANT_IA_H_
# define	INCANT_IA_H_

/*
** PROTOTYPES
*/

int	*set_ressources(t_stck *s, int fd, int *players);
int	check_ressource_for_incant(t_stck *s, int fd);
int	*get_players_from_case(t_stck *s, int fd);
void	upgrade_level(t_stck *s, int fd, int *players);

/*
** PROTOTYPES
*/

#endif /* !INCANT_IA_H_ */
