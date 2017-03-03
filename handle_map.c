/*
** handle_map.c for  in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 18:36:37 2017 anatole zeyen
** Last update Fri Mar  3 19:02:26 2017 anatole zeyen
*/

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
	  printf("%d,%d\n",x, sizey / 2 + y);
	  map[x][sizey / 2 + y] = figure.tetris[x][y];
	  y++;
	}
      y = 0;
      x++;
    }
  return (map);
}
