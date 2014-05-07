#ifndef PARSE_REDIR_H__
# define PARSE_REDIR_H__

/* function */
int	parse_command_redir(char *command);
int	get_mask(char *command);
char	*check_name(char **command);

#endif /* PARSE_REDIR_H_ */

