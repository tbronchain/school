#ifndef		CHECK_TEAM_H_
# define	CHECK_TEAM_H_

/*
** PROTOTYPES
*/

int	get_teams(t_stck *s, int ac, char **av);
int	check_team_nb(t_stck *s, int fd, char *cmd);
char	*check_team_names(t_stck *s, char *team);
int	get_team_c(t_teams *list, char *team);
void	mod_team_c(t_teams *list, char *team, int flag);

#endif /* !CHECK_TEAM_H_ */
