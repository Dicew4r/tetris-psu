/*
** my_put_nbr.c for my_put_nbr in /home/anatole.zeyen/CPool_Day03
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Thu Oct  6 08:07:23 2016 anatole zeyen
** Last update Wed Mar  1 18:16:24 2017 Antoine
*/

#include <unistd.h>
#include <sys/stat.h>
#include "tetris.h"

int		get_size(char *av1, int size)
{
  struct stat	sb;

  if (stat(av1, &sb) != 0)
    {
      write(2, "error\n", 6 );
      return (0);
    }
  size = sb.st_size + 1;
  return (size);
}

int	my_putnbr(int nb)
{
  int	x;

  x = 0;
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1 ;
      my_putnbr(nb);
    }
  else if (nb >= 0 && nb <= 9)
    {
      my_putchar(nb + '0');
    }
  else if (nb > 9)
  {
    my_putnbr(nb / 10);
    x = nb % 10;
    my_putchar(x + '0');
  }
  return (x);
}
