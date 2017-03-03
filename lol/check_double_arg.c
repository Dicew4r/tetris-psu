/*
** check_double_arg.c for  in /home/anatole.zeyen/PSU_2016_tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Wed Mar  1 10:18:51 2017 anatole zeyen
** Last update Wed Mar  1 23:33:40 2017 Antoine
*/

#include <stdlib.h>
#include "tetris.h"

static char	*modif_str(char *str, t_opt *av, int x)
{
  if (my_strcmp(av[x].name, "l") == 0 || my_strcmp(av[x].name, "level") == 0)
    (str[0] == '*') ? (str[0] = '1') : (str[0] = '2');
  if (my_strcmp(av[x].name, "kl") == 0 || my_strcmp(av[x].name, "key-left")
      == 0)
    (str[1] == '*') ? (str[1] = '1') : (str[1] = '2');
  if (my_strcmp(av[x].name, "kr") == 0 || my_strcmp(av[x].name, "key-right")
      == 0)
    (str[2] == '*') ? (str[2] = '1') : (str[2] = '2');
  if (my_strcmp(av[x].name, "kt") == 0 || my_strcmp(av[x].name, "key-turn")
      == 0)
    (str[3] == '*') ? (str[3] = '1') : (str[3] = '2');
  if (my_strcmp(av[x].name, "kd") == 0 || my_strcmp(av[x].name, "key-drop")
      == 0)
    (str[4] == '*') ? (str[4] = '1') : (str[4] = '2');
  if (my_strcmp(av[x].name, "kq") == 0 || my_strcmp(av[x].name, "key-quit")
      == 0)
    (str[5] == '*') ? (str[5] = '1') : (str[5] = '2');
  if (my_strcmp(av[x].name, "kp") == 0 || my_strcmp(av[x].name, "key-pause")
      == 0)
    (str[6] == '*') ? (str[6] = '1') : (str[6] = '2');
  if (my_strcmp(av[x].name, "map-size") == 0)
    (str[7] == '*') ? (str[7] = '1') : (str[7] = '2');
  return (str);
}

int	check_double_arg(t_opt *args, int nb)
{
  char	*str;
  int	x;

  x = 0;
  str = my_strdup("*********");
  while (x <= nb)
    {
      str = modif_str(str, args, x);
      x++;
    }
  x = 0;
  while (str[x])
    {
      if (str[x] == '2')
	return (84);
      x++;
    }
  return (0);
}
