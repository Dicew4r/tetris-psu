/*
** main.c for  in /home/anatole.zeyen/tetris
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Wed Mar  1 15:41:48 2017 anatole zeyen
** Last update Mon Mar  6 17:51:50 2017 anatole zeyen
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
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
  mvprintw(6, COLS - 5, " ");
  addch(level + 48);
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

t_figure	*init_fig_check_help(t_figure *figure, t_struct *infos,
			       int ac, char **av)
{
  int	x;

  x = 0;
  if (ac >= 2)
    {
      while (av[++x])
	if (my_strcmp(av[x], "--help") == 0)
	  {
	    my_disp_help(av[0]);
	    exit(0);
	  }
    }
  if ((figure = malloc(sizeof(t_figure))) == NULL)
    exit(84);
  return (figure);
}

int		main(int ac, char **av)
{
  char		**map;
  char		**ascii;
  t_struct	*infos;
  t_figure	*figure;
  int		x;

  x = 0;
  figure = NULL;
  infos = NULL;
  map = NULL;
  ascii = NULL;
  figure = init_fig_check_help(figure, infos, ac, av);
  infos = prep_infos(infos, figure, ac, av);
  figure = recieve_tetri_init_ncurse(figure, av);
  ascii = open_ascii(ascii);
  map = create_map(map, infos->sizex, infos->sizey * 2);
  while (1)
    {
      x = tetrimino_actions_loop(map, figure, x);
      map = map_actions_loop(map, infos, ascii, infos->level);
      //infos->level++;
      my_sleep(infos->level);
    }
  free(map);
  endwin();
  return (0);
}
