/*
** algo.c for  in /home/marque_p/rendu/sudoku-bi
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Feb 28 00:10:54 2016 Kamil Marque
** Last update Sun Feb 28 15:11:02 2016 Kamil Marque
*/

#include "sudoku.h"

t_list                  *my_create_list(t_list *racine)
{
  if ((racine = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  racine->prec = racine;
  racine->next = racine;
  return (racine);
}

void                    *ajouteravant(t_list *racine, int val, int x, int y)
{
  t_list                *nouvel_element;

  if ((nouvel_element = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  nouvel_element->val = val;
  nouvel_element->pos_x = x;
  nouvel_element->pos_y = y;
  nouvel_element->nb = 1;
  nouvel_element->next = racine;
  racine->prec->next = nouvel_element;
  nouvel_element->prec = racine->prec;
  racine->prec = nouvel_element;
}

int			my_check_col(char **tab, int y)
{
  int			x;
  int			val;

  val = 0;
  x = 0;
  while (x != 9)
    {
      if (tab[x][y] != ' ')
	val++;
      x++;
    }
  return (val);
}

int			my_check_line(char **tab, int x)
{
  int			y;
  int			val;

  val = 0;
  y = 0;
  while (y != 9)
    {
      if (tab[x][y] != ' ')
	val++;
      y++;
    }
  return (val);
}

int			my_check_tab(char **tab, int x, int y)
{
  int			val;
  int			max_x;
  int			max_y;

  val = 0;
  x = x - (x % 3);
  y = y - (y % 3);
  max_y = y + 3;
  max_x = x + 3;
  while (x < max_x)
    {
      while (y < max_y)
	{
	  if (tab[x][y] != ' ')
	    val++;
	  y++;
	}
      x++;
      y = 0;
    }
  return (val);
}
