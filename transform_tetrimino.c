/*
** transform_tetrimino.c for  in /home/anatole.zeyen/tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 16:01:02 2017 anatole zeyen
** Last update Fri Mar  3 16:24:21 2017 anatole zeyen
*/

#include <unistd.h>

char	**recreate_tetrimino(char **tetrimino, char **figure, int x, int y)
{
  int	z;

  x = 0;
  y = 0;
  z = 0;
  while (tetrimino[x])
    {
      while (tetrimino[x][y])
	{
	  if (tetrimino[x][y] == ' ')
	    {
	      figure[x][z++] = ' ';
	      figure[x][z++] = ' ';
	    }
	  else
	    {
	      figure[x][z++] = tetrimino[x][y];
	      figure[x][z++] = '*';
	    }
	  y++;
	}
      z = 0;
      y = 0;
      x++;
    }
  return (figure);
}

char	**transform_tetrimino(char **tetrimino)
{
  char	**figure;
  int	x;

  x = 0;
  while (tetrimino[x])
    x++;
  if ((figure = malloc(sizeof(char *) * (x + 1))) == NULL)
    return (NULL);
  x = 0;
  while (tetrimino[x])
    {
      if ((figure[x] = malloc(sizeof(char) *
			      (len(tetrimino[x]) * 2 + 1))) == NULL)
	return (NULL);
      x++;
    }
  figure[x] = NULL;
  figure = recreate_tetrimino(tetrimino, figure, 0, 0);
  return (figure);
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
  tab[0] = strdup("*");
  tab[1] = strdup("**");
  tab[2] = strdup(" **");
  tab[3] = strdup(" **");
  tab[4] = NULL;
  tab = transform_tetrimino(tab);
  printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
}
