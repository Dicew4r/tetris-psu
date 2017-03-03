/*
** my_strdup.c for my_strdup in /home/anatole.zeyen/CPool_Day08
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Wed Oct 12 13:54:44 2016 anatole zeyen
** Last update Fri Mar  3 18:01:45 2017 Antoine
*/

#include <stdlib.h>
#include "tetris.h"

char	*my_strdup(char *src)
{
  int	x;
  int	u;
  char	*dest;

  x = 0;
  u = len(src);
  if ((dest = malloc(sizeof(char) * (u + 1))) == NULL)
    return (NULL);
  while (src[x] != '\0')
    {
      dest[x] = src[x];
      x = x + 1;
    }
  dest[x] = '\0';
  return (dest);
}
