/*
** debug.c for tetris in /home/anatole.zeyen/PSU_2016_tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Mon Feb 27 10:20:49 2017 anatole zeyen
** Last update Mon Mar  6 15:43:39 2017 anatole zeyen
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"

int	is_d_flag(char **av)
{
  int	x;

  x = 0;
  while (av[x])
    {
      if (my_strcmp(av[x], "-d") == 0)
	return (0);
      else if (my_strcmp(av[x], "--debug") == 0)
	return (0);
      x++;
    }
  return (1);
}

void	convert_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	my_putstr("(space)");
      else
	my_putchar(str[i]);
      i++;
    }
}

void	print_key_debug(t_struct *infos)
{
  my_putstr("*** DEBUG MODE ***\nKey Left : ");
  convert_space(infos->kl);
  my_putstr("\nKey Right : ");
  convert_space(infos->kr);
  my_putstr("\nKey Turn : ");
  convert_space(infos->kt);
  my_putstr("\nKey Drop : ");
  convert_space(infos->kd);
  my_putstr("\nKey Quit : ");
  convert_space(infos->kq);
  my_putstr("\nKey Pause : ");
  convert_space(infos->kp);
}

int		debug(char **av, t_struct *infos, t_figure *figure)
{
  char	**list;

  infos = init_infos(infos, av);
  verif_param(infos);
  if (is_d_flag(av) == 1)
    return (1);
  if (infos->error == 84)
    {
      my_putstr("wrong parameters\n");
      exit(84);
    }
  print_key_debug(infos);
  my_putstr("\nNext : ");
  (infos->next == 1) ? (write(1, "Yes\n", 4)) : (write (1, "No\n", 3));
  my_putstr("Level : ");
  my_putnbr(infos->level);
  my_putstr("\nSize : ");
  my_putnbr(infos->sizex);
  my_putchar('*');
  my_putnbr(infos->sizey);
  my_putchar('\n');
  list = sort_d_name("tetriminos", av[0]);
  figure = my_display_array(list, "tetriminos", figure);
  printf("%s\n", figure[3].tetris[2]);
  return (0);
}
