/*
** main.c for  in /home/marque_p/rendu/PSU_2016_lemipc
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Mar 29 14:01:19 2017 Kamil Marque
** Last update Wed Mar 29 14:46:20 2017 Kamil Marque
*/

#include "../include/my.h"

int		main(int ac, char **av)
{
  if (ac != 3)
    {
      my_usage();
      return (0);
    }
  else
    printf("%s\n",av[1]);
}
