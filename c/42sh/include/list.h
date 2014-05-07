#ifndef LIST_H_
# define LIST_H_

#include "struct_termcap.h"

/*function*/
void	my_put_list(t_list_recup_char *recup);
void	free_list(t_list_recup_char *recup);
int	listlen(t_list_recup_char *recup);

#endif /* LIST_H_ */
