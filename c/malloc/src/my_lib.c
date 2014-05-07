#include <string.h>
#include <unistd.h>

void	my_putchar(char c)
{
  int	res;

  res = write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	res;

  res = write(1, str, strlen(str));
}

void		my_put_hexa(unsigned int nb)
{
  int		i;
  unsigned char	num;
  unsigned int	filtr;

  i = 28;
  filtr = 0xF0000000;
  while (filtr)
    {
      num = (filtr & nb) >> i;
      if (num > 9)
	my_putchar(num + 55);
      else
	my_putchar(num + '0');
      filtr = filtr >> 4;
      i -= 4;
    }
}

void	my_put_nbr(unsigned int nb)
{
  char	num;
  int	i;
  int	flag;

  flag = 0;
  i = 100000000;
  while (i >= 1)
    {
      num = (nb / i) % 10 + 0x30;
      if ((num != '0' || flag == 1) || (i == 1 && flag == 0))
        {
          flag = 1;
          my_putchar(num);
        }
      i /= 10;
    }
}

int	my_fputs(char *str, int fd)
{
  return (write(fd, str, strlen(str)));
}
