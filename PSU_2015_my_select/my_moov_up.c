/*
** my_moov_up.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb 24 14:20:53 2016 Kamil Marque
** Last update Wed Feb 24 14:24:46 2016 Kamil Marque
*/

#include "my.h"

void    my_moov_up3(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->select == 3)
    {
      tmp->prec->select = 1;
      tmp->select = 2;
    }
  else
    {
      tmp->prec->select = 1;
      tmp->select = 0;
    }
}

void    my_moov_up2(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->prec->select == 2)
    {
      if (tmp->select == 3)
	{
	  tmp->prec->select = 3;
	  tmp->select = 2;
	}
      else
	{
	  tmp->prec->select = 3;
	  tmp->select = 0;
	}
    }
  else
    my_moov_up3(list, check, tmp);
}

void    my_moov_up(t_list *list, t_check *check)
{
  t_list        *tmp;

  tmp = list->next;
  while (tmp->select != 1 && tmp->select != 3)
    tmp = tmp->next;
  if (tmp->prec == list)
    {
      if (tmp->select == 3)
	tmp->prec->select = 2;
      else
	tmp->select = 0;
      if (tmp->prec->prec->select == 0)
	tmp->prec->prec->select = 1;
      else if (tmp->prec->prec->select == 2)
	tmp->prec->prec->select = 3;
    }
  my_moov_up2(list, check, tmp);
}
