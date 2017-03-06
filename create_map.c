/*
** create_map.c for map in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 15:29:05 2017 anatole zeyen
** Last update Mon Mar  6 10:06:41 2017 anatole zeyen
*/

#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

char	**place_map(char **map, int sizex, int sizey)
{
  int	x;

  x = 1;
  while (map[x + 1])
    {
      mvprintw(LINES / 2 - (sizex / 2) + x, (COLS / 2 - sizey / 2) + 1, map[x]);
      x++;
    }
  return (map);
}

char	**place_borders(char **map, int j, int y, int x)
{
  j = 0;
  while (j != y + 2)
    {
      map[0][j] = '!';
      map[x + 1][j] = '!';
      j++;
    }
  return (map);
}

char	**create_map(char **map, int x, int y)
{
  int	j;
  int	i;

  j = 0;
  i = 0;
  if ((map = malloc(sizeof(char *) * (x + 3))) == NULL)
    return (NULL);
  while (j != x + 2)
    {
      if ((map[j] = malloc(sizeof(char) * y + 3)) == NULL)
	return (NULL);
      map[j][0] = '!';
      while (i != y)
	map[j][++i] = ' ';
      i = 0;
      map[j][y + 1] = '!';
      map[j][y + 2] = '\0';
      j++;
    }
  map[j] = '\0';
  map = place_borders(map, j, y, x);
  return (map);
}
