/*
** fonctions.c for  in /home/marque_p/rendu/CPE_2015_n4s/kamel/test2
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Sat May 28 14:55:40 2016 kamil
** Last update Sat May 28 14:57:21 2016 kamil
*/

#include "get_next_line.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

int		my_strlen(char *str)
{
  int		i;

  while (str[i])
    i++;
  return (i);
}
