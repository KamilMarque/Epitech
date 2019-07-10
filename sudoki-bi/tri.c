/*
** tri.c for  in /home/marque_p/rendu/sudoku-bi
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Feb 28 01:45:04 2016 Kamil Marque
** Last update Sun Feb 28 15:23:48 2016 Kamil Marque
*/

#include "sudoku.h"

void                     my_mouv_lb(t_list *racine, t_list *racine2)
{
  racine->next->prec = racine2;
  racine->next = racine->next->next;
  racine->next->prec->next = racine2->next;
  racine2->next = racine->next->prec;
  racine->next->prec = racine;
  racine2->next->next->prec = racine2->next;
}

void			rotation_la(t_list *racine)
{
  t_list                *tmp;

  tmp = racine->next;
  racine->next = racine->next->next;
  racine->next->prec = racine;
  racine->prec->next = tmp;
  tmp->prec = racine->prec;
  racine->prec = tmp;
  tmp->next = racine;
}

void			my_tri_list2(t_list *list, t_list *list2)
{
  t_list		*tmp;
  t_list		*tmp2;

  tmp = list->next;
  tmp2 = tmp;
  while (tmp != list)
    {
      if (tmp2->val < tmp->val)
	tmp2 = tmp;
      tmp = tmp->next;
    }
  while (tmp != tmp2)
    {
      rotation_la(list);
      tmp = list->next;
    }
}

t_list			*my_tri_list(t_list *list, t_list *list2)
{
  while (list->next != list)
    {
      my_tri_list2(list, list2);
      my_mouv_lb(list, list2);
    }
  return (list2);
}
