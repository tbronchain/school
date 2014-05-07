#ifndef		CBUF_H_
# define	CBUF_H_


/*
** PROTOTYPES
*/

int	add_buffer(t_buf *buf, t_stck *s, char *src, int len);
char	*get_buffer(t_buf *buf, t_stck *s, int fd, int flag);
int	test_buffer(t_buf *buf);


#endif /* !CBUF_H_ */
