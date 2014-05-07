#ifndef		LIB_H_
# define	LIB_H_


/*
** PROTOTYPES
*/

char	*str_clean(char *str);
char	**verif_wordtab(char *buf, char token);
char	**str_to_wordtab(char *s, char token);
int	count(char **p);
int	get_block(int nb);


#endif /* !LIB_H_ */
