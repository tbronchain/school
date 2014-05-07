/*
** main.c for nm-objdump in /u/all/bronch_t/cu/rendu/c/nm-objdump/src_objdump
** 
** Made by thibault bronchain
** Login   <bronch_t@epitech.net>
** 
** Started on  Mon Mar 29 23:25:03 2010 thibault bronchain
** Last update Thu Apr  1 17:16:34 2010 thibault bronchain
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

static void	display_char(unsigned char *addr, int i, int max)
{
  int		count;

  count = 0;
  while (count != 16 && i < max)
    {
      if (addr[i] >= 32 && addr[i] < 127)
	putchar(addr[i]);
      else if (i < max)
	putchar('.');
      i++;
      count++;
    }
}

static void	display_hexa(unsigned char *addr, int i, int max)
{
  int		count;

  count = 0;
  while (count != 16)
    {
      if (!(count % 4) && count)
	putchar(' ');
      if (i >= max)
	printf("  ");
      else if (addr[i] < 0xff)
	printf("%02x", addr[i]);
      else
	printf("ff");
      i++;
      count++;
    }
}

static void	display_section(unsigned char *addr,
				int size,
				unsigned int mem_addr)
{
  int		i;

  i = 0;
  while (i < size)
    {
      printf(" %04x ", (unsigned int)mem_addr + i);
      display_hexa(addr, i, size);
      printf("  ");
      display_char(addr, i, size);
      putchar('\n');
      i += 16;
    }
}

void		find_section(Elf32_Ehdr *elf)
{
  Elf32_Shdr	*sec;
  char		*name;
  int		i;

  sec = (void *)(elf->e_shoff + (unsigned int)elf);
  i = 1;
  while (i != elf->e_shnum)
    {
      name = (char *)(sec[i].sh_name + sec[elf->e_shstrndx].sh_offset
		      + (unsigned int)elf);
      printf("Contents of section %s:\n", name);
      display_section((unsigned char *)(sec[i].sh_offset
					+ (unsigned int)elf), sec[i].sh_size,
		      (unsigned int)sec[i].sh_addr);
      if (!strcmp(name, ".comment"))
	break;
      i++;
    }
}
