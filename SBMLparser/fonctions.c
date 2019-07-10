/*
** fonctions.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 13:53:48 2016 kamil
** Last update Mon Jun 13 13:58:54 2016 kamil
*/

#include "my.h"

static void		my_putchar(char c)
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

static void		my_putchar_error(char c)
{
  write(2, &c, 1);
}

void		my_putstr_error(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    my_putchar_error(str[i++]);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
