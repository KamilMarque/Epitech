/*
** my_putstr.c for  in /home/marque_p/rendu/Piscine_C_J04
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Thu Oct  1 08:54:41 2015 Kamil Marque
** Last update Thu Nov 12 18:39:18 2015 Kamil Marque
*/

#include <stdio.h>

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      write(2, "(null)", 7);
      return (1);
    }
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
