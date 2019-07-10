/*
** my_moov_down.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb 24 14:25:31 2016 Kamil Marque
** Last update Wed Feb 24 19:01:50 2016 Kamil Marque
*/

#include "my.h"

void		my_moov_down3(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->select == 3)
    {
      tmp->next->select = 1;
      tmp->select = 2;
    }
  else
    {
      tmp->next->select = 1;
      tmp->select = 0;
    }
}

void		my_moov_down2(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->next->select == 2)
    {
      if (tmp->select == 3)
	{
	  tmp->next->select = 3;
	  tmp->select = 2;
	}
      else
	{
	  tmp->next->select = 3;
	  tmp->select = 0;
	}
    }
  else
    my_moov_down3(list, check, tmp);
}

void		my_moov_down(t_list *list, t_check *check)
{
  t_list        *tmp;

  tmp = list->next;
  while (tmp->select != 1 && tmp->select != 3)
    tmp = tmp->next;
  if (tmp->next == list)
    {
      if (tmp->select == 3)
	tmp->select = 2;
      else
	tmp->select = 0;
      if (list->next->select == 0)
	list->next->select = 1;
      else
	list->next->select = 3;
    }
  else
    my_moov_down2(list, check, tmp);
}
