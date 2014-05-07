/*
** main.c for nm-objdump in /u/all/bronch_t/cu/rendu/c/nm-objdump/src_objdump
** 
** Made by thibault bronchain
** Login   <bronch_t@epitech.net>
** 
** Started on  Mon Mar 29 23:25:03 2010 thibault bronchain
** Last update Thu Apr  1 17:34:29 2010 thibault bronchain
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include "objdump.h"
#include "header.h"
#include "sections.h"
#include "xfunct.h"
#include "xfunct2.h"

static void	*init(struct stat *s, char *fname)
{
  void		*buf;
  int		fd;

  fd = xopen(fname, O_RDONLY);
  xfstat(fd, s);
  buf = xmmap(NULL, s->st_size, PROT_READ, MAP_FILE, fd, 0);
  xclose(fd);
  return (buf);
}

int		main(int ac, char **av)
{
  Elf32_Ehdr	*elf;
  struct stat	s;
  int		i;

  if (ac < 2)
    {
      fputs("syntax error\nusage: my_objdump <file> ...\n", stderr);
      return (EXIT_FAILURE);
    }
  i = 1;
  while (i < ac)
    {
      elf = init(&s, av[i++]);
      find_header(elf);
      find_section(elf);
      xmunmap((void *)elf, s.st_size);
    }
  return (EXIT_SUCCESS);
}
