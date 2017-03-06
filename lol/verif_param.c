/*
** verif_param.c for verif_param.c in /home/homegan/projects/PSU_2016_tetris
** 
** Made by Antoine
** Login   <antoine.le-du@epitech.eu>
** 
** Started on  Fri Mar  3 15:22:16 2017 Antoine
** Last update Mon Mar  6 14:53:57 2017 anatole zeyen
*/

#include "tetris.h"

void	verif_param(t_struct *infos)
{
  if (my_strcmp(infos->kl, infos->kr) == 0 || my_strcmp(infos->kl, infos->kt) == 0
      || my_strcmp(infos->kl, infos->kd) == 0 || my_strcmp(infos->kl, infos->kq) == 0
      || my_strcmp(infos->kl, infos->kp) == 0 || my_strcmp(infos->kr, infos->kt) == 0
      || my_strcmp(infos->kr, infos->kd) == 0 || my_strcmp(infos->kr, infos->kq) == 0
      || my_strcmp(infos->kr, infos->kp) == 0 || my_strcmp(infos->kt, infos->kd) == 0
      || my_strcmp(infos->kt, infos->kq) == 0 || my_strcmp(infos->kt, infos->kp) == 0
      || my_strcmp(infos->kd, infos->kq) == 0 || my_strcmp(infos->kd, infos->kp) == 0
      || my_strcmp(infos->kq, infos->kp) == 0)
    infos->error = 84;
}
