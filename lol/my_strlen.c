/*
** my_strlen.c for my_strlen in /home/adrien.rouhete/CPool_Day04
** 
** Made by Adrien Rouhète
** Login   <adrien.rouhete@epitech.net>
** 
** Started on  Fri Oct  7 14:43:07 2016 Adrien Rouhète
** Last update Wed Mar  1 15:27:57 2017 Antoine
*/

#include <unistd.h>
#include "tetris.h"

void	my_putstr(char *str)
{
  write(1, str, len(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	len(char *str)
{
  int	x;

  x = 0;
  while (str[x])
    x++;
  return (x);
}
