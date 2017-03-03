/*
** my_getnbr.c for getnbr in /home/anatole.zeyen/CPE_2016_matchstick
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Mon Feb 13 15:43:37 2017 anatole zeyen
** Last update Wed Mar  1 18:18:32 2017 Antoine
*/

#include <unistd.h>
#include "tetris.h"

int	numbers(int c)
{
  return (((c >= 48 && c <= 57) ? (1) : (0)));
}

int	my_space(int c)
{
  return (((c == 32 ||  (c >= 9 && c <= 13))) ? (1) : (0));
}

int		my_getnbr(char *str)
{
  unsigned int	number;
  int		sign;
  int		x;

  sign = 1;
  x = 0;
  number = 0;
  if (str == NULL)
    return (-1);
  while (my_space(str[x]) == 1)
    x = x + 1;
  if (str[x] == '-' || str[x] == '+')
  {
    if (str[x] == '-')
      sign = -1;
    x = x + 1;
  }
  while (str[x] && numbers(str[x]) == 1)
  {
    number = number * 10 + str[x] - 48;
    x = x + 1;
  }
  return ((int)number * sign);
}
