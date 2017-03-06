/*
** fcts_arrays.c for fcts_arrays.c in /home/homegan/projects/PSU_2016_tetris
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Wed Mar  1 16:07:10 2017 Antoine
** Last update Mon Mar  6 09:57:59 2017 anatole zeyen
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tetris.h"

static void	my_print_sizecolor(char	**first_line)
{
  my_putstr(" : Size ");
  my_putstr(first_line[0]);
  my_putchar('*');
  my_putstr(first_line[1]);
  my_putstr(" : Color ");
  my_putstr(first_line[2]);
  my_putstr(" :\n");
}

t_figure	fill_figure(char **tab, int max, t_figure figure)
{
  int	x;

  x = 1;
  while (tab[x] && x <= max)
    x++;
  if ((figure.tetris = malloc(sizeof(char *) * x + 1)) == NULL)
    return (figure);
  x = 1;
  while (tab[x] && x <= max)
    {
      figure.tetris[x - 1] = my_strdup(tab[x]);
      x++;
    }
  figure.tetris[x - 1] = NULL;
  figure.height = max;
  return (figure);
}

t_figure	my_prompt_figure(char **tab, char *name, int error, t_figure figure)
{
  char	**first_line;
  int	x;

  x = 1;
  first_line = my_str_to_wordtab(tab[0], ' ');
  name = recreate_name(name);
  my_putstr("Tetriminos : Name ");
  my_putstr(name);
  if (error == 84)
    {
      figure.tetris = NULL;
      my_putstr(" : Error\n");
      return (figure);
    }
  my_print_sizecolor(first_line);
  figure = fill_figure(tab, my_getnbr(first_line[1]), figure);
  while (tab[x] && x <= (my_getnbr(first_line[1])))
    {
      my_putstr(tab[x]);
      my_putchar('\n');
      x++;
    }
  return (figure);
}

int	verif_figure(char **tab, int lines)
{
  int	x;
  int	y;

  x = 1;
  y = 0;
  while (tab[x] && x != lines)
    {
      while (tab[x][y])
	{
	  if (tab[x][y] != ' ' && tab[x][y] != '*')
	    return (84);
	  y++;
	}
      y = 0;
      x++;
    }
  return (0);
}

int	my_fakestrlen(char *str)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (str[x])
    {
      if (x == 0 && str[x] == ' ')
	y++;
      x++;
    }
  if (str[x - 1] == ' ')
    y++;
  return (x - y);
}

char    **please_sort_this_array(char **array, int size, char *path)
{
  int	x;

  x = 1;
  while (x < size)
    {
      if (my_strcmp(array[x - 1], array[x]) > 0)
	swap_elem(&array[x] , &array[x - 1]);
      x = x + 1;
    }
  x = 1;
  while (x < size)
    {
      if (my_strcmp(array[x - 1], array[x]) > 0)
	please_sort_this_array(array, size, path);
      x = x + 1;
    }
  return (array);
}
