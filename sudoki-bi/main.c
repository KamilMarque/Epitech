/*
** main.c for  in /home/henry_g/sudoku-bi
** 
** Made by Clément Henry
** Login   <henry_g@epitech.net>
** 
** Started on  Sun Feb 28 03:39:58 2016 Clément Henry
** Last update Sun Feb 28 21:14:05 2016 Kamil Marque
*/

#include "sudoku.h"

void		map_error()
{
  printf("MAP ERROR\n\n");
  exit (0);
}

int		my_check_mid(char **tab, int *x, int *y)
{
  if (*x == 0 || *x == 10)
    {
      if (tab[*x][*y] != '-')
	map_error();
    }
  else
    {
      if (*y % 2 == 0)
	{
	  if (tab[*x][*y] > '9' && tab[*x][*y] < '1')
	    map_error();
	}
      else
	if (tab[*x][*y] != ' ')
	  map_error();
    }
}

int		check_map(char **tab)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (tab[x])
    {
      if (strlen(tab[x]) != 20)
	map_error();
      if (tab[x][y] != '|')
	map_error();
      y++;
      while (tab[x][y + 1])
	{
	  my_check_mid(tab, &x, &y);
	  y++;
	}
      if (tab[x][y] != '|')
	map_error();
      x++;
      y = 0;
    }
  return (1);
}

void		my_sudoku(char **av)
{
  char		**tab;
  t_list	*list;
  t_list	*list2;

  tab = fill_map(list, list2);
}

int		main(int ac, char **av)
{
  if (ac > 1)
    exit (0);
  else
    {
      my_sudoku(av);
    }
  return (0);
}
