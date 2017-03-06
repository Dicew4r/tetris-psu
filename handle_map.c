/*
** handle_map.c for  in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 18:36:37 2017 anatole zeyen
** Last update Mon Mar  6 11:33:47 2017 anatole zeyen
*/

#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"

char	**add_tetrimino(char **map, t_figure figure, int sizex, int sizey)
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
	    return (map);
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
  return (map);
}

char	**fall_map(char	**map)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (map[x])
    x++;
  x = x - 3;
  while (x != 1)
    {
      map[x] = my_strncpy(map[x], map[x - 1], len(map[x]));
      x--;
    }
  while (map[1][y])
    {
      if (map[1][y] == '*')
	map[1][y] = ' ';
      y++;
    }
  return (map);
}
