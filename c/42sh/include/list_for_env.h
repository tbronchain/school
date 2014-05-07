#ifndef LIST_FOR_ENV_H_
# define LIST_FOR_ENV_H_

#include "struct.h"

/*function*/
int	my_put_in_tab(t_list *begin, char **sort);
void	my_list_tab_cpy(char **src, t_list **begin);
int	my_put_in_list(t_list **begin, char *data);
int	find_in_list_env(t_list *begin, char *str);
void	free_tab(char **tabs);

#endif /* LIST_FOR_ENV_H_ */
