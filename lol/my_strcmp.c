/*
** my_strcmp.c for lib in my_strcmp.c
** 
** Made by Erwan Bernard
** Login   <erwan.bernard@epitech.eu>
** 
** Started on  Thu Jan 05 11:38:03 2017 Erwan Bernard
** Last update Mon Feb 20 15:05:58 2017 anatole zeyen
*/

#include <unistd.h>
#include "tetris.h"

int	my_strcmp(char *s1, char *s2)
{
  while (s1 != NULL && s2 != NULL && (*s1 != 0 || *s2 != 0))
  {
    if (*s1 != *s2)
      return (*s1 - *s2);
    s1++;
    s2++;
  }
  if (s1 == NULL)
    return (- *s2);
  if (s2 == NULL)
    return (*s1);
  return (*s1 - *s2);
}
