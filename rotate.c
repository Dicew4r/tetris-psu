/*
** rotate.c for  in /home/anatole.zeyen/PSU_2016_tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 14:09:44 2017 anatole zeyen
** Last update Fri Mar  3 14:54:43 2017 anatole zeyen
*/

#include <unistd.h>

char	**move_left(char **tetris, char **tetrisbis)
{
  int	x;
  int	y;
  int	ln;

  x = 0;
  y = 0;
  while (tetris[x])
    {
      ln = len(tetris[x]) - x;
      while (tetris[x][y])
	{
	  tetrisbis[x + y][ln];
	  printf("->[%d][%d]\n", x + y, ln);
	  y++;
	}
      printf("\n");
      //tetrisbis[x + y][ln] = '\0';
      y = 0;
      x++;
    }
  tetrisbis[x] = '\0';
  return (tetrisbis);
}

char	**rotate_left(char **tetris)
{
  int	x;
  char	**tetrisbis;

  x = 0;
  while (tetris[x])
    x++;
  if ((tetrisbis = malloc(sizeof(char *) * (x + 1))) == NULL)
    return (NULL);
  x = 0;
  while (tetris[x])
    {
      if ((tetrisbis = malloc(sizeof(char) * len(tetris[x]))) == NULL)
	return (NULL);
      x++;
    }
  tetrisbis = move_left(tetris, tetrisbis);
  return (tetrisbis);
}

int	main(int ac, char **av)
{
  char	**tetris;
  char	**bis;

  tetris = malloc(sizeof(char *) * 4);
  tetris[0] = malloc(sizeof(char) * 5);
  tetris[1] = malloc(sizeof(char) * 5);
  tetris[2] = malloc(sizeof(char) * 5);
  tetris[3] = NULL;
  tetris[0] = "123\0";
  tetris[1] = "4\0";
  tetris[2] = "567\0";
  int x = 0;
  bis = rotate_left(tetris);
  while (bis[x])
    {
      my_putstr(bis[x]);
      x++;
    }
}
