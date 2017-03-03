/*
** tools.c for  in /home/anatole.zeyen/PSU_2016_tetris
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue Feb 21 09:55:59 2017 anatole zeyen
** Last update Thu Feb 23 11:51:08 2017 anatole zeyen
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

char	*recreate_name(char *name)
{
  int	x;
  int	y;
  char	*str;

  y = 0;
  x = 1;
  while (name[x] != '.' && name[x])
    x++;
  if ((str = malloc(sizeof(char) * x + 1)) == NULL)
    return (NULL);
  y = x;
  str[y + 1] = '\0';
  while (name[y] && name[y] != '/')
    y--;
  y++;
  x = 0;
  while (name[y] != '.')
    {
      str[x] = name[y];
      y++;
      x++;
    }
  str[x] = '\0';
  return (str);
}

int	is_nbr(char *str)
{
  int	x;

  x = 0;
  while (str[x])
     {
       if (numbers(str[x]) == 0)
	 return (0);
       x++;
     }
  return (1);
}
