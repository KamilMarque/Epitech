/*
** algo2.c for  in /home/marque_p/rendu/sudoku-bi
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Feb 28 15:10:07 2016 Kamil Marque
** Last update Sun Feb 28 15:10:43 2016 Kamil Marque
*/

#include "sudoku.h"

int                     my_final_val(char **tab, int x, int y)
{
  int                   res;

  res = my_check_col(tab, y);
  res = my_check_line(tab, x) + res;
  res = my_check_tab(tab, x, y) + res;
  return (res);
}

t_list                  *my_att_pos(char **tab)
{
  t_list                *root;
  int                   x;
  int                   y;
  int                   val;

  x = 0;
  y = 0;
  root = my_create_list(root);
  while (tab[x])
    {
      while (tab[x][y])
	{
	  if (tab[x][y] == ' ')
	    {
	      val = my_final_val(tab, x, y);
	      ajouteravant(root, val, x, y);
	    }
	  y++;
	}
      x++;
      if (x == 9)
	return (root);
      y = 0;
    }
  return (root);
}
