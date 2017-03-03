/*
** init.c for init in /home/anatole.zeyen/PSU_2016_my_sokoban/bonus
** 
** Made by anatole zeyen
** Login   <anatole.zeyen@epitech.net>
** 
** Started on  Sun Dec 18 10:49:14 2016 anatole zeyen
** Last update Fri Mar  3 10:29:27 2017 anatole zeyen
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

void	init()
{
  start_color();
  attron(COLOR_PAIR(4));
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  // attroff(COLOR_PAIR(4));
}

void	init2()
{
  start_color();
  attron(COLOR_PAIR(2));
  init_pair(2, COLOR_RED, COLOR_BLACK);
  //attroff(COLOR_PAIR(2));
}

void	init3()
{
  start_color();
  attron(COLOR_PAIR(3));
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  //attroff(COLOR_PAIR(3));
}

void	init4()
{
  start_color();
  attron(COLOR_PAIR(9));
  init_pair(9, COLOR_GREEN, COLOR_BLACK);
  //attroff(COLOR_PAIR(9));
}
