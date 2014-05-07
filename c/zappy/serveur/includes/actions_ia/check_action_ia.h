#ifndef		CHECK_ACTION_IA_H_
# define	CHECK_ACTION_IA_H_


/*
** PROTOTYPES
*/

int	set_egg(t_stck *s, int fd);
int	set_incantation(t_stck *s, int fd, int pause, int (*funct)());
int	set_fork(t_stck *s, int fd, int pause, int (*funct)());
int	finish_incantation(t_stck *s, int fd);
int	check_action_ia(t_stck *s, int fd, char *cmd);

/*
** PROTOTYPES
*/

typedef struct	s_cmd_ia
{
  char		*cmd;
  int		(*funct)();
  int		param;
  int		(*funct_wait)();
}		t_cmd_ia;

#endif /* !CHECK_ACTION_IA_H_ */
