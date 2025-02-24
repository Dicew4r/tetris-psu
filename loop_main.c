/*
** loop_main.c for  in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Mon Mar  6 17:31:19 2017 anatole zeyen
** Last update Thu Mar  9 10:46:19 2017 anatole zeyen
*/

#include <stdlib.h>
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

char	**map_actions_loop(char **map, t_struct *infos, char **ascii)
{
  print_map(ascii, infos->level, 0);
  place_map(map, infos->sizex, infos->sizey);
  place_game(infos->sizex + 1, infos->sizey + 1);
  infos->level++;
  return (map);
}

int	tetrimino_actions_loop(char **map, t_figure *figure, int x,
			       t_struct *info)
{
  int	y;

  y = 0;
  if (!figure[x].tetris)
    x++;
  if (figure[x].tetris)
    {
      while (figure_blocked(figure[x], map, x + 1, y + 1) != 0)
	{
	  verif_loose(map);
	  print_map(map, info->level);
	  place_map(map, info->sizex, info->sizey);
	  place_game(info->sizex + 1, info->sizey + 1);
	  print_figure(figure[x], x + 1, y + 1, info);
	  y++;
	  refresh();
	  clear();
	  usleep(90000);
	}
      if (x > 6)
	x = 0;
      add_figure(figure[x], map, x + 1, y + 1);
      info->level++;
    }
  x++;
  print_next_tetrimino(figure, x);
  if (x >= 6)
    x = 0;
  return (x);
}

void		my_sleep(int level)
{
  static float	slip = 8.0f;

  refresh();
  clear();
  sleep(1);
  slip = slip - 0.25;
}
