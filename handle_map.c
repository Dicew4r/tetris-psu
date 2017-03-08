/*
** handle_map.c for  in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 18:36:37 2017 anatole zeyen
** Last update Wed Mar  8 14:44:35 2017 anatole zeyen
*/

#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"

void	print_next_tetrimino(t_figure *figure, int x)
{
  int	y;

  y = 0;
  if (!figure[x].tetris)
    x++;
  while (figure[x].tetris[y])
    {
      mvprintw(10 + y, COLS - 11, figure[x].tetris[y]);
      y++;
    }
}

int	add_tetrimino(char **map, t_figure figure, int var, int sizey)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (figure.tetris[x])
    {
      while (figure.tetris[x][y])
	{
	  if (map[x + 1][sizey / 2 + y] == '*')
	    return (var - 1);
	  y++;
	}
      y = 0;
      x++;
    }
  x = 0;
  y = 0;
  while (figure.tetris[x])
    {
      while (figure.tetris[x][y])
	{
	  map[x + 1][sizey / 2 + y] = figure.tetris[x][y];
	  y++;
	}
      y = 0;
      x++;
    }
  return (var);
}

char	**fall_map(char	**map)
{
  int	x;
  int	y;
  int	aled;

  x = 0;
  y = 0;
  while (map[x])
    x++;
  x = x - 3;
  while (map[x][y])
    {
      if (map[x][y] == '*')
	{
	  x--;
	  y = 0;
	}
      y++;
    }
  y = 0;
  while (x > 1)
    {
      map[x] = my_strncpy(map[x], map[x - 1], len(map[x]));
      x--;
    }
  y = 0;
  while (map[1][y])
    {
      if (map[1][y] == '*')
	map[1][y] = ' ';
      y++;
    }
  return (1);
}
