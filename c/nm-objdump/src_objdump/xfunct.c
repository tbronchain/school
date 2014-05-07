/*
** xfunct.c for epikong in /u/all/dulieu_p/public/rush/epikong/etape_1/src
** 
** Made by thibault bronchain
** Login   <bronch_t@epitech.net>
** 
** Started on  Sat Mar 27 20:31:19 2010 thibault bronchain
** Last update Thu Apr  1 17:30:56 2010 thibault bronchain
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int	xopen(char *pathname, int flags)
{
  int	res;

  if ((res = open(pathname, flags)) == -1)
    {
      fprintf(stderr, "Can't open %s.\n", pathname);
      exit(EXIT_FAILURE);
      puts(" rgr ");
    }
  return (res);
}

int	xclose(int fd)
{
  int	res;

  if ((res = close(fd)) == -1)
    {
      fprintf(stderr, "Can't perform close().\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

int	xread(int fd, void *buff, int size)
{
  int	res;

  if ((res = read(fd, buff, size)) == -1)
    {
      fprintf(stderr, "Can't perform read().\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

int	xwrite(int fd, void *buff, int size)
{
  int	res;

  if ((res = write(fd, buff, size)) == -1)
    {
      fprintf(stderr, "Can't perform write().\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}

int	xfstat(int fd, struct stat *buf)
{
  int	res;

  if ((res = fstat(fd, buf)) == -1)
    {
      fprintf(stderr, "Can't perform fstat().\n");
      exit(EXIT_FAILURE);
    }
  return (res);
}
