/*
** xfunct2.h for nm-objdump in /u/all/bronch_t/cu/rendu/c/nm-objdump/includes_objdump
** 
** Made by thibault bronchain
** Login   <bronch_t@epitech.net>
** 
** Started on  Tue Mar 30 00:08:29 2010 thibault bronchain
** Last update Thu Apr  1 15:43:00 2010 thibault bronchain
*/

#ifndef XFUNCT2_H_
# define XFUNCT2_H_


/*
** PROTOTYPES
*/

void	*xmalloc(int size);
void	*xmmap(void *addr, size_t len, int prot, int flags, int fd, off_t off);
int	xmunmap(void *addr, size_t length);


#endif /* !XFUNCT2_H_ */
