/*
** main.c for  in /home/anatole.zeyen/tetris
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Wed Mar  1 15:41:48 2017 anatole zeyen
** Last update Fri Mar  3 19:35:54 2017 anatole zeyen
*/

#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"

char    **print_map(char **map, int level, int y)
{
  int	x;
  x = 0;
  init();
  while (map[x])
    {
      mvprintw(LINES / 10 + x, COLS / 10, map[x]);
      x++;
    }
  init4();
  mvprintw(4, COLS - 10, "level");
  init2();
  mvprintw(8, COLS - 15, "Next tetrimino");
  mvprintw(9, COLS - 15, " ");
  hline(42, 15);
  vline(42, 6);
  mvprintw(15, COLS - 15, " ");
  hline(42, 14);
  mvprintw(9, COLS - 2, " ");
  vline(42, 6);
  init3();
  mvprintw(16, COLS - 10, "level:");
  if (LINES < 40 || COLS < 80)
    {
      clear();
      init4();
      mvprintw(LINES / 2 - (1 / 2), COLS / 2 - 12, "please resize the window");
    }
  return (map);
}

int	place_game(int sizex, int sizey)
{
  mvprintw(LINES / 2 - (sizex / 2), (COLS / 2 - sizey / 2), " ");
  vline(0, sizex);
  mvprintw(LINES / 2 - (sizex / 2) + 1, (COLS / 2 + sizey * 1.5), " ");
  vline(0, sizex - 1);
  mvprintw((LINES / 2) - (sizex / 2), (COLS / 2) - (sizey / 2), " ");
  hline(0, sizey * 2);
  mvprintw((LINES / 2) + (sizex / 2), (COLS / 2) - (sizey / 2), " ");
  hline(0, sizey * 2);
  return (0);
}

char	**open_ascii(char **ascii)
{
  char  fuffer[10000];
  int   datboi;
  int   fd;

  fd = open("ascii_tetris", O_RDONLY, 0666);
  if ((datboi = read(fd, fuffer, 9999)) == -1)
    return (NULL);
  fuffer[datboi] = '\0';
  ascii = my_str_to_wordtab(fuffer, '\n');
  close(fd);
  return (ascii);
}

int     main(int ac, char **av)
{
  int	event;
  char	**map;
  char	**ascii;
  t_figure	*figure;
  int	x;

  x = 0;
  debugmain(ac, av, figure);
  initscr();
  keypad(stdscr,TRUE);
  curs_set(FALSE);
  ascii = open_ascii(ascii);
  map = create_map(map, 20, 10 * 2); // coords pareil
  while (1)
    {
      map = add_tetrimino(map, figure[x], 20, 10);
      x++;
      print_map(ascii, 0, 0);
      place_map(map, 20, 10); // encore
      place_game(20 + 1, 10 + 1); // ENVOYER LES COORDS ICI
      refresh();
      clear();
      if (x == 6)
	x = 0;
    }
  endwin();
  return (0);
}
