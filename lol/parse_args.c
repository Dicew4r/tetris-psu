/*
** parse_args.c for parse_args in /home/homegan/projects/PSU_2016_tetris
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Wed Mar  1 14:48:21 2017 Antoine
** Last update Fri Mar  3 18:00:58 2017 Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ncurses.h>
#include "tetris.h"

static int	is_valid_arg(char *str)
{
  if (my_strcmp(str, "-l") == 0 || my_strcmp(str, "--level") == 0
      || my_strcmp(str, "-kl") == 0 || my_strcmp(str, "--key-left") == 0
      || my_strcmp(str, "-kr") == 0 || my_strcmp(str, "--key-right") == 0
      || my_strcmp(str, "-kt") == 0 || my_strcmp(str, "--key-turn") == 0
      || my_strcmp(str, "-kd") == 0 || my_strcmp(str, "--key-drop") == 0
      || my_strcmp(str, "-kq") == 0 || my_strcmp(str, "--key-quit") == 0
      || my_strcmp(str, "-kp") == 0 || my_strcmp(str, "--key-pause") == 0
      || my_strcmp(str, "--map-size") == 0)
    return (1);
  else if (my_strcmp(str, "--help") == 0|| my_strcmp(str, "-w") == 0
	   || my_strcmp(str, "--without-next") == 0
	   || my_strcmp(str, "-d") == 0 || my_strcmp(str, "--debug") == 0)
    return (0);
  else
    return (-1);
}

static int	arg_dash(t_opt *args, int index_av, char **av, int arg_pos)
{
  if (is_valid_arg(av[index_av]) == 1)
    {
      args[arg_pos].name = av[index_av] + 1;
      if (!av[index_av + 1] || len(av[index_av + 1]) < 1)
	return (84);
      args[arg_pos].value = av[index_av + 1];
      return (index_av + 2);
    }
  else if (is_valid_arg(av[index_av]) == 0)
    {
      args[arg_pos].name = av[index_av] + 1;
      args[arg_pos].value = NULL;
      return (index_av + 1);
    }
  else
    return (84);
}

static int	dbl_dash(t_opt *args, int index_av, char **av, int arg_pos)
{
  if (count_x_in_str(av[index_av], '=') == 0)
    {
      if (is_valid_arg(av[index_av]) != 0)
	return (84);
      args[arg_pos].name = av[index_av] + 2;
      args[arg_pos].value = NULL;
      return (index_av + 1);
    }
  else if (is_valid_arg(before_equal(av[index_av])) == 1)
    {
      args[arg_pos].name = before_equal(av[index_av] + 2);
      if (len(after_equal(av[index_av])) < 1)
	return (84);
      args[arg_pos].value = after_equal(av[index_av]);
      return (index_av + 1);
    }
  else
    return (84);
}

int	full_opt(t_opt *args, int index_av, char **av, int arg_pos)
{
  if (len(av[index_av]) < 2)
    return (84);
  if (av[index_av][0] == '-' && av[index_av][1] == '-'
      && len(av[index_av]) > 3)
    {
      if ((index_av = dbl_dash(args, index_av, av, arg_pos)) == 84)
	return (84);
      return (index_av);
    }
  else if (av[index_av][0] == '-' && av[index_av][1] != '-')
    {
      if ((index_av = arg_dash(args, index_av, av, arg_pos)) == 84)
	return (84);
      return (index_av);
    }
  return (84);
}
