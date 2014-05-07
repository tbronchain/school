#ifndef		FORK_IA_H_
# define	FORK_IA_H_


/*
** PROTOTYPES
*/

t_egg	*add_egg_in_list(t_egg **begin, t_egg *new);
void	del_egg_in_list(t_egg **begin, t_egg *del, t_stck *s);
int	del_egg(t_stck *s, int egg_id, int flag);
int	set_timeout_for_egg(t_stck *s,
				int fd,
				int pause,
				int (*funct_wait)());
int	egg_born(t_stck *s, int egg_id);

#endif /* !OFRK_IA_H_ */
