/*
** handle_map.c for  in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 18:36:37 2017 anatole zeyen
** Last update Thu Mar  9 10:43:13 2017 anatole zeyen
*/

#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"

void	print_next_tetrimino(t_figure *figure, int x)
{
  int	y;
  int	a;

  y = 0;
  a = 0;
  if (!figure[x].tetris[0])
    x++;
  if (x > 6)
    x = 1;
  while (figure[x].tetris[y])
    {
      move(10 + y, COLS - 11);
      while (figure[x].tetris[y][a])
	{
	  if (figure[x].tetris[y][a] == '*')
	    addch(figure[x].tetris[y][a]);
	  a++;
	}
      a = 0;
      y++;
    }
}

int	figure_blocked(t_figure figure, char **map, int y, int x)
{
  int	a;
  int	b;
  int	save;

  a = 0;
  while (figure.tetris[a])
    a++;
  --a;
  if (a < 0 || !figure.tetris[a])
    return (0);
  b = 0;
  while (figure.tetris[a][b])
    {
      save = a;
      while (figure.tetris[a][b] != '*' && figure.tetris[a][b])
	a = a - 1;
      if (map[x + a + 1][y + b] != ' ')
	return (0);
      a = save;
      b++;
    }
  return (1);
}

void	print_figure(t_figure figure, int x, int y, t_struct *info)
{
  int	k;

  k = 0;
  while (figure.tetris[k])
    {
      mvprintw(LINES / 2 - (info->sizex / 2) + k + y, (COLS / 2 - info->sizey / 2) + x + 1, figure.tetris[k]);
      k++;
    }
}

void	add_figure(t_figure figure, char **map, int x, int y)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (figure.tetris[a])
    {
      while (figure.tetris[a][b])
	{
	  if (figure.tetris[a][b] == '*')
	    map[y + a][x + b] = figure.tetris[a][b];
	  b++;
	}
      b = 0;
      a++;
    }
}

void	verif_loose(char **map)
{
  int	x;

  x = 0;
  while (map[1][x])
    {
      if (map[1][x] == '*')
	{
	  clear();
	  mvprintw(LINES / 2, COLS / 2, "Defeat");
	  refresh();
	  sleep(2);
	  endwin();
	  free(map);
	  exit(0);
	}
      x++;
    }
}
