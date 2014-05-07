#ifndef XFUNCTION_TERMCAP_NEXT_H_
# define XFUNCTION_TERMCAP_NEXT_H_

/* function.c */
void	xtputs(char *str, int affcnt, int (*my_outc)(int));
char	**xmalloc_2d(char **tabs, int size);
char	*x_malloc(char *str, int size);

#endif /* XFUNCTION_TERMCAP_NEXT_H_ */
