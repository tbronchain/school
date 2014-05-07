#ifndef		LIST_BUF_H_
# define	LIST_BUF_H_


/*
** PROTOTYPES
*/

t_buf_c	*new_buffer(t_buf *buf, t_stck *s, int len);
void	del_buffer(t_buf *buf, t_stck *s);
void	free_buffer(t_buf_c **begin);
void	free_buffer_list(t_stck *s);


#endif /* !LIST_BUF_H_ */
