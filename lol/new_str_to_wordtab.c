/*
** STRTOWORDTABE.C for jean mamadou in /home/anatole.zeyen/Graph_prog
**
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
**
** Started on  Wed Nov 23 15:53:48 2016 anatole zeyen
** Last update Wed Mar  1 15:20:01 2017 Antoine
**
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"

int	maloc_str(char *str, int x, char charact)
{
  int	compteur2;

  compteur2 = 0;
  while (str[x] && str[x] != charact)
    {
      compteur2 = compteur2 + 1;
      x = x + 1;
    }
  return (compteur2);
}

int	word_count(char *str, char charact)
{
  int	x;
  int	compteur;

  x = 0;
  compteur = 1;
  while (str[x])
    {
      if (str[x] == charact)
	compteur = compteur + 1;
      x = x + 1;
    }
  return (compteur);
}

char		**my_str_to_wordtab(char *str, char charact)
{
  char		**tab;
  int		x;
  int		y;
  int		z;

  x = 0;
  z = 0;
  y = 0;
  if ((tab = malloc(sizeof(char *) * (word_count(str, charact) + 1))) == NULL)
    return (NULL);
  while (str[x] != '\0')
    {
      y = 0;
      if ((tab[z] = malloc(sizeof(char) * (maloc_str(str, x, charact) + 1)))
	  == NULL)
	return (NULL);
      while (str[x] && str[x] != charact)
	tab[z][y++] = str[x++];
      tab[z++][y] = '\0';
      if (str[x])
	x = x + 1;
    }
  tab[z] = '\0';
  return (tab);
}
