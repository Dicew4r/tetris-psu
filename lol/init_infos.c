/*
** init_infos.c for init_infos.c in /home/homegan/projects/PSU_2016_tetris
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Wed Mar  1 16:44:49 2017 Antoine
** Last update Fri Mar  3 20:41:31 2017 Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "tetris.h"

static int	calc_ac(char **av)
{
  int	ac;

  ac = 0;
  while (av[ac])
    ac++;
  return (ac);
}

static void	fullfill_infos_next(t_struct *infos, t_opt *args, int i)
{
  char	**map;

  if (my_strcmp(args[i].name, "kd") == 0
      || my_strcmp(args[i].name, "key-drop") == 0)
    infos->kd = args[i].value;
  else if (my_strcmp(args[i].name, "kq") == 0
	   || my_strcmp(args[i].name, "key-quit") == 0)
    infos->kq = args[i].value;
  else if (my_strcmp(args[i].name, "kp") == 0
	   || my_strcmp(args[i].name, "key-pause") == 0)
    infos->kp = args[i].value;
  else if (my_strcmp(args[i].name, "l") == 0
	   || my_strcmp(args[i].name, "level") == 0)
    infos->level = my_getnbr(args[i].value);
  else if (my_strcmp(args[i].name, "w") == 0
	   || my_strcmp(args[i].name, "without-next") == 0)
    infos->next = 0;
  else if (my_strcmp(args[i].name, "map-size") == 0)
    {
      map = my_str_to_wordtab(args[i].value, ',');
      infos->sizex = my_getnbr(map[0]);
      infos->sizey = my_getnbr(map[1]);
    }
}

static void	fullfill_infos(t_struct *infos, t_opt *args, int nb)
{
  int	i;

  i = 0;
  while (i <= nb)
    {
      if (my_strcmp(args[i].name, "kr") == 0
	  || my_strcmp(args[i].name, "key-right") == 0)
	infos->kr = args[i].value;
      else if (my_strcmp(args[i].name, "kl") == 0
	       || my_strcmp(args[i].name, "key-left") == 0)
	infos->kl = args[i].value;
      else if (my_strcmp(args[i].name, "kt") == 0
	       || my_strcmp(args[i].name, "key-turn") == 0)
	infos->kt = args[i].value;
      else
	fullfill_infos_next(infos, args, i);
      i++;
    }
}

static int	modif_infos(t_struct *infos, char **av)
{
  t_opt		*args;
  int		ac;
  int		index_av;
  int		arg_pos;

  index_av = 1;
  arg_pos = 0;
  if ((ac = calc_ac(av))> 10)
    return (84);
  if ((args = malloc(sizeof(t_opt) * ac)) == NULL)
    return (84);
  while (index_av < ac)
    {
      if ((index_av = full_opt(args, index_av, av, arg_pos)) == 84)
	{
	  infos->error = 84;
	  return (0);
	}
      arg_pos++;
    }
  if (check_double_arg(args, index_av - 3) == 84)
    infos->error = 84;
  fullfill_infos(infos, args, index_av - 2);
  return (0);
}

t_struct	*init_infos(t_struct *infos, char **av)
{
  infos->kl = my_strdup("^EOD");
  infos->kr = my_strdup("^EOC");
  infos->kt = my_strdup("^EOA");
  infos->kd = my_strdup("^EOB");
  infos->kq = my_strdup("q");
  infos->kp = my_strdup(" ");
  infos->next = 1;
  infos->level = 1;
  infos->sizex = 20;
  infos->sizey = 10;
  infos->error = 0;
  modif_infos(infos, av);
  return (infos);
}
