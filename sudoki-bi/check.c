/*
** check.c for  in /home/henry_g/sudoku-bi
** 
** Made by Clément Henry
** Login   <henry_g@epitech.net>
** 
** Started on  Sun Feb 28 00:11:30 2016 Clément Henry
** Last update Sun Feb 28 19:44:39 2016 Kamil Marque
*/

#include "sudoku.h"

int		horizontal(char **map, int i, char nb)
{
  int		j;

  j = -1;
  while (++j < 9)
    if (map[i][j] == nb + 48)
      return (0);
  return (1);
}

int		vertical(char **map, int j, char nb)
{
  int		i;

  i = -1;
  while (++i < 9)
    if (map[i][j] == nb + 48)
      return (0);
  return (1);
}

int		square(char **map, char nb, int i, int j)
{
  int		tmp;
  int		tmp_2;

  i = i - (i % 3);
  j = j - (j % 3);
  tmp = i + 3;
  tmp_2 = j + 3;
  while (i < tmp)
    {
      while (j < tmp_2)
	{
	  if (map[i][j] == nb + 48)
	    return (0);
	  j++;
	}
      j = tmp_2 - 3;
      i++;
    }
  return (1);
}

t_list		*solve_it2(char **map, t_list *tmp, int *cpt)
{
  if ((horizontal(map, tmp->pos_x, tmp->nb)) == 1)
    {
      if (vertical(map, tmp->pos_y, tmp->nb) == 1)
	{
	  if (square(map, tmp->nb, tmp->pos_x, tmp->pos_y) == 1)
	    {
	      map[tmp->pos_x][tmp->pos_y] = tmp->nb + 48;
	      *cpt = 1;
	      tmp = tmp->prec;
	    }
	  else
	    tmp->nb++;
	}
      else
	tmp->nb++;
    }
  else
    tmp->nb++;
  return (tmp);
}

char		**solve_it(char **map, t_list *list)
{
  t_list	*tmp;
  int		cpt;

  cpt = 0;
  tmp = list->prec;
  while (tmp != list)
    {
      while (tmp->nb <= 9 && cpt != 1)
	tmp = solve_it2(map, tmp, &cpt);
      cpt = 0;
      if (tmp->nb >= 9)
	{
	  tmp->nb = 1;
	  map[tmp->pos_x][tmp->pos_y] = ' ';
	  if (tmp->next == list)
	    {
	      map = false_map(map);
	      return (map);
	    }
	  tmp = tmp->next;
	}
    }
  return (map);
}
