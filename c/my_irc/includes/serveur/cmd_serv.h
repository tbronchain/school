#ifndef		CMD_SERV_H_
# define	CMD_SERV_H_

/*
** PROTOTYPES
*/

int	nick(t_stck *s, int fd, char **cmd);
int	list(t_stck *s, int fd, char **cmd);
int	join(t_stck *s, int fd, char **cmd);
int	part(t_stck *s, int fd, char **cmd);
int	users(t_stck *s, int fd, char **cmd);
int	msg(t_stck *s, int fd, char **cmd);
int	quit(t_stck *s, int fd, char **cmd);
int	me(t_stck *s, int fd, char **cmd);


/*
** STRUCTURE
*/

typedef struct	s_cmd
{
  char		*cmd;
  int		(*funct)();
}		t_cmd;


#endif /* !CMD_SERV_H_ */
