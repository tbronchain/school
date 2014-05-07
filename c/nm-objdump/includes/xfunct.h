/*
** xfunct.h for nm-objdump in /u/all/bronch_t/cu/rendu/c/nm-objdump/includes_objdump
** 
** Made by thibault bronchain
** Login   <bronch_t@epitech.net>
** 
** Started on  Tue Mar 30 00:08:03 2010 thibault bronchain
** Last update Tue Mar 30 00:08:05 2010 thibault bronchain
*/

#ifndef XFUNCT_H_
# define XFUNCT_H_


/*
** PROTOTYPES
*/

int	xopen(char *pathname, int flags);
int	xclose(int fd);
int	xread(int fd, void *buff, int size);
int	xwrite(int fd, void *buff, int size);
int	xfstat(int fd, struct stat *buf);


#endif /* !XFUNCT_H_ */
