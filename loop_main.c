/*
** loop_main.c for  in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Mon Mar  6 17:31:19 2017 anatole zeyen
** Last update Wed Mar  8 14:47:41 2017 anatole zeyen
*/

#include <ncurses.h>
#include "tetris.h"

t_struct	*prep_infos(t_struct *infos, t_figure *figure,
			    int ac, char **av)
{
  if ((infos = malloc(sizeof(t_struct))) == NULL)
    exit(84);
  infos = init_infos(infos, av);
  infos = debugmain(ac, av, figure, infos);
  return (infos);
}

t_figure	*recieve_tetri_init_ncurse(t_figure *figure, char **av)
{
  char		**list;

  list = sort_d_name("tetriminos", av[0]);
  figure = my_display_array(list, "tetriminos", figure);
  initscr();
  keypad(stdscr,TRUE);
  curs_set(FALSE);
  return (figure);
}

char	**map_actions_loop(char **map, t_struct *infos, char **ascii, int level)
{
  int	x;

  x = fall_map(map);
  print_map(ascii, level, 0);
  place_map(map, infos->sizex, infos->sizey);
  place_game(infos->sizex + 1, infos->sizey + 1);
  infos->level++;
  refresh();
  clear();
  return (map);
}

int	tetrimino_actions_loop(char **map, t_figure *figure, int x)
{
  if (figure[x].tetris)
    x = add_tetrimino(map, figure[x], x, 10);
  x++;
  print_next_tetrimino(figure, x);
  if (x >= 7)
    x = 0;
  return (x);
}

void		my_sleep(int level)
{
  static float	slip = 8.0f;

  sleep(2);
  slip = slip - 0.25;
}
