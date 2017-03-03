/*
** fcts_arrays2.c for fcts_arrays2.c in /home/homegan/projects/PSU_2016_tetris
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Wed Mar  1 16:10:01 2017 Antoine
** Last update Wed Mar  1 23:12:56 2017 Antoine
*/

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tetris.h"

static int	my_second_parsing(char **tab, char **first_line)
{
  int	x;
  int	verif;

  x = 1;
  verif = 0;
  if (my_getnbr(first_line[2]) > 255 || my_getnbr(first_line[2]) < 0)
    return (84);
  while (tab[x] && x <= (my_getnbr(first_line[1])))
    {
      if (my_fakestrlen(tab[x]) > my_getnbr(first_line[0]))
	return (84);
      if (my_fakestrlen(tab[x]) == my_getnbr(first_line[0]))
	verif = 1;
      x++;
    }
  if (verif == 0)
    return (84);
  return (verif_figure(tab, my_getnbr(first_line[0]) - 1));
}

int	my_parsing(char **tab)
{
  int	x;
  char	**first_line;

  x = 0;
  first_line = my_str_to_wordtab(tab[0], ' ');
  if (tab == NULL)
    return (84);
  while (first_line[x])
    x++;
  if (x != 3)
    return (84);
  if ((is_nbr(first_line[2]) == 0) || (is_nbr(first_line[1]) == 0) ||
      (is_nbr(first_line[0]) == 0))
    return (84);
  x = 0;
  while (tab[x])
    x++;
  if ((x - 1) < my_getnbr(first_line[1]))
    return (84);
  return (my_second_parsing(tab, first_line));
}

void	swap_elem(char **index1, char **index2)
{
  char	*variable;

  variable = *index1;
  *index1 = *index2;
  *index2 = variable;
}

void    my_display_array(char **array, char *path)
{
  int	x;
  int	y;
  char	*str;

  x = 0;
  y = 0;
  while (array[y])
    y++;
  my_putstr("Tetriminos :  ");
  my_putnbr(y);
  my_putchar('\n');
  while (array[x])
    {
      str = my_strcat(path, array[x]);
      prompt_one_file(str);
      x = x + 1;
    }
}

char		**sort_d_name(char *str, char *av1)
{
  DIR		*fun;
  struct dirent	*dirent;
  char		**list;
  int		x;

  fun = NULL;
  dirent = NULL;
  x = 0;
  list = malloc(sizeof(char *) * 100);
  fun = opendir(str);
  if (str == NULL)
    return (0);
  while ((dirent = readdir(fun)) != NULL)
    {
      if (is_tetrimino(dirent->d_name) == 0)
	{
	  list[x] = my_strdup(dirent->d_name);
	  x = x + 1;
	}
      list[x] = NULL;
    }
  list = please_sort_this_array(list, x, av1);
  return (list);
}
