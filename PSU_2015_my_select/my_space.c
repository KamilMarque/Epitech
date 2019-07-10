/*
** my_space.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb 24 14:29:30 2016 Kamil Marque
** Last update Wed Feb 24 19:31:01 2016 Kamil Marque
*/

#include "my.h"

void    my_backspace(t_list *list, t_check *check)
{
  t_list      *tmp;

  tmp = list->next;
  while (tmp->select != 1 && tmp->select != 3)
    tmp = tmp->next;
  tmp->next->prec = tmp->prec;
  tmp->prec->next = tmp->next;
  if (tmp->next == list)
    tmp = tmp->next;
  if (tmp->next->select == 2)
    tmp->next->select = 3;
  if (tmp->select == 3)
    check->nb_word_return--;
  if (tmp->next->select == 0)
    tmp->next->select = 1;
  else if (tmp->next->select == 2)
    tmp->next->select == 3;
  check->nb_elem--;
  if (check->nb_elem == 0)
    {
      endwin();
      exit(0);
    }
}

void		my_space3(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->next->select == 2)
    {
      tmp->next->select = 3;
      tmp->select = 2;
      check->nb_word_return++;
    }
  else
    {
      tmp->select = 2;
      tmp->next->select = 1;
      check->nb_word_return++;
    }
}

void		my_space2(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->select == 3)
    {
      if (tmp->next->select == 2)
	{
	  tmp->next->select = 3;
	  tmp->select = 0;
	  check->nb_word_return--;
	}
      else
	{
	  tmp->select = 0;
	  tmp->next->select = 1;
	  check->nb_word_return--;
	}
    }
  else
    my_space3(list, check, tmp);
}

void		my_space(t_list *list, t_check *check)
{
  t_list        *tmp;

  tmp = list->next;
  while (tmp->select != 1 && tmp->select != 3)
    tmp = tmp->next;
  if (tmp->next == list)
    {
      if (tmp->select == 1)
	{
	  tmp->select = 2;
	}
      else
	tmp->select = 3;
      if (tmp->next->next->select == 0)
	tmp->next->next->select = 1;
      else
	tmp->next->next->select = 3;
    }
  my_space2(list, check, tmp);
}
