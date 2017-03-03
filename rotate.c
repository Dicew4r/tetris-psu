/*
** rotate.c for  in /home/anatole.zeyen/PSU_2016_tetris
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Fri Mar  3 14:09:44 2017 anatole zeyen
** Last update Fri Mar  3 15:13:41 2017 anatole zeyen
*/

#include <unistd.h>

int	len(char *str)
{
  int x = 0;
  while (str[x])
    x++;
  return (x);
}

char	**move_left(char **tetris, char **tetrisbis)
{
  int	i;
  int	j;
  int	ln;

  i = 0;
  j = 0;
  while (tetris[i])
    {
      while (tetris[i][j])
	{
	  //tetrisbis[j][len(tetris[i]) - i] = tetris[i][j];
	  printf("->[%d][%d]\n",j, len(tetris[i]) - i);
	  j++;
	}
      printf("\n");
      j = 0;
      i++;
    }
  tetrisbis[i] = '\0';
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
      printf("%s", bis[x]);
      x++;
    }
}
