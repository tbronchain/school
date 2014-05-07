#ifndef MAKE_REDIR_H__
# define MAKE_REDIR_H__

/* function */
int	parse_command_r_redir(char *command, int opt);
int	parse_command_l_redir(char *command, int opt);
int	exec_command(char *command);

#endif /* MAKE_REDIR_H_ */

