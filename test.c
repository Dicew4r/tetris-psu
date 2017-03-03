/*
** test.c for test in /home/homegan/projects/PSU_2016_tetris
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Fri Mar  3 15:48:13 2017 Antoine
** Last update Fri Mar  3 16:17:45 2017 Antoine
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	cyclic_rot(char a, char b, char c, char d)
{
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	print_tab(char **tab)
{
  int	i;
  int	j;

  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  my_putchar(tab[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
}

void	my_putstr(char *c)
{
  int  i;

  i = 0;
  while (c[i] != '\0')
    {
      my_putchar(c[i]);
      i++;
    }
}

int	main()
{
  char	**tab;
  int	i;
  int	j;
  int	n;
  char	temp;

  n = 4;
  i = 0;
  tab = malloc(sizeof(char *) * 5);
  tab[0] = strdup("*---");
  tab[1] = strdup("**--");
  tab[2] = strdup("-**-");
  tab[3] = strdup("-**-");
  tab[4] = NULL;
  print_tab(tab);
  while (i < (n / 2))
    {
      j = 0;
      while (j < ((n + 1) / 2))
	{
	  temp = tab[i][j];
	  tab[i][j] = tab[n - 1 - j][i];
	  tab[n - 1 - j][i] = tab[n - 1 - i][n - 1 - j];
	  tab[n - 1 - i][n - 1 - j] = tab[j][n - 1 - i];
	  tab[j][n - 1 - i] = temp;
	  j++;
	}
      i++;
    }
  my_putstr("Rotate : 90\n");
  print_tab(tab);
}
