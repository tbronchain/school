#ifndef		LIST_H_
# define	LIST_H_


/*
** PROTOTYPES
*/

t_wait	*add_in_list(t_wait **begin, t_wait *new);
void	del_in_list(t_wait **begin, t_wait *del);
void	free_list(t_wait **begin);


#endif /* !LIST_H_ */
