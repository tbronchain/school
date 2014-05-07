/*
** xfunct.c for epikong in /u/all/dulieu_p/public/rush/epikong/etape_1/src
** 
** Made by thibault bronchain
** Login   <bronch_t@epitech.net>
** 
** Started on  Sat Mar 27 20:31:19 2010 thibault bronchain
** Last update Thu Apr  1 15:42:57 2010 thibault bronchain
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

void	*xmalloc(int size)
{
  void	*res;

  if (!(res = malloc(size)))
    {
      fprintf(stderr, "Can't alloc memory.\n");
      exit(EXIT_FAILURE);
    }
  memset(res, 0, size);
  return (res);
}

void	*xmmap(void *addr, size_t len, int prot, int flags, int fd, off_t off)
{
  void	*res;

  if ((res = mmap(addr, len, prot, flags, fd, off)) == MAP_FAILED)
    {
      fprintf(stderr, "Can't alloc memory.\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

int	xmunmap(void *addr, size_t length)
{
  int	res;

  if ((res = munmap(addr, length)) == -1)
    {
      fprintf(stderr, "Can't free memory.\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}
