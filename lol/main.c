/*
** main.c for main in /home/anatole.zeyen/PSU_2016_tetris
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Mon Feb 20 13:50:25 2017 anatole zeyen
** Last update Fri Mar  3 18:04:48 2017 anatole zeyen
*/

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "tetris.h"

t_figure	prompt_one_file(char *name, t_figure figure)
{
  int	fd;
  char	*fuffer;
  int	size;
  int	datboi;
  char	**tab;

  tab = NULL;
  size = 100;
  if ((size = get_size(name, size)) == 0)
    return (figure);
  if ((fuffer = malloc(sizeof(char) * size)) == NULL)
    return (figure);
  if ((fd = open(name, O_RDONLY)) == - 1)
    return (figure);
  if ((datboi = read(fd, fuffer, size)) == 0)
    return (figure);
  fuffer[datboi] = '\0';
  close(fd);
  tab = my_str_to_wordtab(fuffer, '\n');
  fd = my_parsing(tab);
  figure = my_prompt_figure(tab, name, fd, figure);
  free(fuffer);
  return (figure);
}

char	*my_strcat(char *path, char *name)
{
  int	x;
  int	y;
  char	*str;

  x = 0;
  y = 0;
  if ((str = malloc(sizeof(char) * (len(path) + len(name) + 2))) == NULL)
    return (NULL);
  while (path[x])
    {
      str[x] = path[x];
      x++;
    }
  if (str[x - 1] != '/')
    {
      str[x] = '/';
      x++;
    }
  while (name[y])
    str[x++] = name[y++];
  str[x] = '\0';
  return (str);
}

int	is_tetrimino(char *name)
{
  int	x;
  int	y;
  char	*str;

  x = 0;
  y = 0;
  while (name[x] != '.' && name[x])
    x++;
  if (name[x] != '.')
    return (84);
  str = malloc(sizeof(char) * len(name));
  while (name[x])
    {
      str[y] = name[x];
      y++;
      x++;
    }
  if (my_strcmp(str, ".tetrimino") != 0)
    return (84);
  return (0);
}

static void	my_disp_help(char *av)
{
  my_putstr("Usage:  ");
  my_putstr(av);
  my_putstr(" [options]\n");
  my_putstr("Options:\n   --help\t\tDisplay this help\n");
  my_putstr("   -l --level={num}\tStart Tetris at level num (def:  1)\n");
  my_putstr("   -kl --key-left={K}\tMove the tetrimino LEFT using the K");
  my_putstr(" key (def:  left arrow)\n   -kr --key-right={K}\tMove the ");
  my_putstr("tetrimino RIGHT using the K key (def:  right arrow)\n");
  my_putstr("   -kt --key-turn={K}\tTURN the tetrimino clockwise 90d ");
  my_putstr("using the K key (def:  top arrow)\n");
  my_putstr("   -kd --key-drop={K}\tDROP the tetrimino using the");
  my_putstr(" K key (def:  down arrow)\n");
  my_putstr("   -kq --key-quit={K}\tQUIT the game using the K key");
  my_putstr(" (def:  'Q' key)\n");
  my_putstr("   -kp --key-pause={K}\tPAUSE/RESTART the game using the K");
  my_putstr(" key (def:  space bar)\n");
  my_putstr("   --map-size={row,col}\tSet the numbers of rows and columns");
  my_putstr(" of the map (def:  20,10)\n");
  my_putstr("   -w --without-next\tHide next tetrimino (def:  false)");
  my_putstr("\n   -d --debug\t\tDebug mode (def:  false)\n");
}

int		main(int ac, char **av)
{
  char		**list;
  int		size;
  struct termios new;
  t_figure	*figure;
  char		c;
  t_struct	*infos;

  size = 0;
  if (ac >= 2)
    {
      while (av[++size])
	if (my_strcmp(av[size], "--help") == 0)
	  {
	    my_disp_help(av[0]);
	    return (0);
	  }
      if ((size = get_size("tetriminos", size)) == 0)
	return (84);
      if (debug(av) == 1)
	{
	  if ((infos = malloc(sizeof(t_struct))) == NULL)
	    exit(84);
	  infos = init_infos(infos, av);
	  if (infos->error == 84)
	    {
	      my_putstr("wrong parameters\n");
	      exit(84);
	    }
	  return (0);
	}
      list = sort_d_name("tetriminos", av[0]);
      figure = NULL;
      figure = my_display_array(list, "tetriminos", figure);
      my_putstr("Press any key to start Tetris\n");
    }
  else if (ac == 1)
    {
    }
  ioctl(0, TCGETS, &new);
  new.c_lflag &= ~ICANON;
  new.c_lflag &= ~ECHO;
  ioctl(0, TCSETS, &new);
  read(0, &c, 1);
  return (0);
}
