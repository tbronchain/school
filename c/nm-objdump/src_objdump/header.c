/*
** main.c for nm-objdump in /u/all/bronch_t/cu/rendu/c/nm-objdump/src_objdump
** 
** Made by thibault bronchain
** Login   <bronch_t@epitech.net>
** 
** Started on  Mon Mar 29 23:25:03 2010 thibault bronchain
** Last update Sat Apr  3 01:29:14 2010 thibault bronchain
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include "objdump.h"
#include "xfunct.h"
#include "xfunct2.h"

void		find_header(Elf32_Ehdr *elf)
{
  Elf32_Phdr	*prog;
  void		*addr;
  int		i;

  prog = (void *)(elf->e_phoff + (unsigned int)elf);
  i = 0;
  while (i != elf->e_phnum)
    {
      addr = (void *)((char *)(prog[i].p_offset + (unsigned int)elf));
      i++;
    }
}
