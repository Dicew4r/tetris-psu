/*
** my_strncpy.c for lib in my_strcpy.c
** 
** Made by Erwan Bernard
** Login   <erwan.bernard@epitech.eu>
** 
** Started on  Thu Jan 05 12:26:23 2017 Erwan Bernard
** Last update Wed Feb 22 17:08:30 2017 anatole zeyen
*/

#include <unistd.h>
#include "tetris.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] && i < n)
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = 0;
  return (dest);
}
