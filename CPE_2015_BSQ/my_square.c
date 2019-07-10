/*
** my_square.c for  in /home/marque_p/rendu/CPE_2015_BSQ
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Dec  9 14:47:42 2015 Kamil Marque
** Last update Sat Dec 19 12:31:22 2015 Kamil Marque
*/

#include "my.h"

int             my_check_square(t_square *square, char **tab, int y, int x)
{
  int   x_tmp;
  int   y_tmp;

  y_tmp = y + square->size_square;
  x_tmp = x + square->size_square;
  while (y != y_tmp && tab[y] != 0)
    {
      while (x != x_tmp)
	{
	  if (tab[y][x] == '.')
	    x++;
	  else
	    return (0);
	}
      x = x_tmp - square->size_square;
      y++;
    }
  if (y == y_tmp)
    return (1);
  else
    return (0);
}

void    my_square(t_square *square, char **tab)
{
  int   x;
  int   y;

  y = 1;
  while (tab[y] != 0)
    {
      x = 0;
      while (tab[y][x] != 0)
	{
	  if (y >= square->pos_y && y < square->pos_y + square->size_square)
	    {
	      if (x >= square->pos_x && x < square->pos_x + square->size_square)
		my_putchar('x');
	      else
		my_putchar(tab[y][x]);
	    }
	  else
	    my_putchar(tab[y][x]);
	  x++;
	}
      free(tab[y]);
      my_putchar('\n');
      y++;
    }
  free(tab);
}

void            my_no_square(t_square *square, char **tab)
{
  square->size_square--;
  if (square->pos_y == -1)
    my_aff_map(square, tab);
  else
    my_square(square, tab);
}
