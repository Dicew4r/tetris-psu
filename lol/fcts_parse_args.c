/*
** fcts_parse_args.c for fcts_parse_args.c in /home/homegan/projects/PSU_2016_tetris
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Wed Mar  1 14:51:32 2017 Antoine
** Last update Fri Mar  3 18:00:40 2017 Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"

int	count_x_in_str(char *str, char c)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	nb++;
      i++;
    }
  return (nb);
}

char	*before_equal(char *str)
{
  int	i;
  char	*str2;

  str2 = my_strdup(str);
  i = 0;
  while (str2[i] != '=')
    i++;
  str2[i] = '\0';
  return (str2);
}

char	*after_equal(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '=')
    i++;
  return (str + i + 1);
}
