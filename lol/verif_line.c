/*
** verif_line.c for  in /home/anatole.zeyen/PSU_2016_tetris/tetriminos
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Tue Feb 28 13:30:03 2017 anatole zeyen
** Last update Wed Mar  1 18:20:41 2017 anatole zeyen
*/

int	is_same_letter(char *str, int x)
{
  int	save;
  int	y;

  save = x;
  y = save;
  while (str[x])
    {
      while (y <= x)
	{
	  if (x != y && str[x] == str[y])
	    return (1);
	  y++;
	}
      y = save;
      x++;
    }
  return (0);
}

int	second_verif(char *name, char *value)
{
  int	x;

  x = 11;
  if (my_strncmp(name, "--key-left=", 11) == 0 ||
      (my_strncmp(name, "--key-turn=", 11) == 0) ||
      (my_strncmp(name, "--key-quit=", 11) == 0) ||
      (my_strncmp(name, "--key-drop=", 11) == 0))
    {
      if (is_same_letter(name, 11) == 1)
	return (84);
    }
  if (my_strncmp(name, "--key-right=", 12) == 0 ||
    my_strncmp(name, "--key-pause=", 12) == 0)
    {
      if (is_same_letter(name, 12) == 1)
	return (84);
    }
  return (0);
}

int	verif_line(char *name, char *value)
{
  int	x;

  x = 0;
  if (name[1] == 'l')
    while (value[x])
      {
	if (numbers(value[x]) == 0)
	  return (84);
	x++;
      }
  if (name[1] == 'k')
    if (is_same_letter(value, 0) == 1)
      return (84);
  if (my_strncmp(name, "--map-size=", 11) == 0)
    {
      x = 11;
      my_putchar(name[x]);
      while (name[x])
	{
	  if (numbers(name[x]) == 0 && name[x] != ',')
	    return (84);
	  x++;
	}
    }
  return (second_verif(name, value));
}

int	main(int ac, char **av)
{
  return (verif_line(av[1], av[2]));
}
