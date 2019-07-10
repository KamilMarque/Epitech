/*
** my_moov_left2.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb 24 19:24:04 2016 Kamil Marque
** Last update Wed Feb 24 19:24:53 2016 Kamil Marque
*/

#include "my.h"

void            check_lef_moov(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->select == 3)
    tmp->select = 2;
  else
    tmp->select = 0;
  if (list->prec->select == 0)
    list->prec->select = 1;
  else
    list->prec->select = 3;
}

int             my_moov_left2(t_list *list, t_check *check, t_list *tmp)
{
  int         pos_line;
  int         pos_row;

  pos_line = tmp->line;
  pos_row = tmp->col - check->col_size - 4;
  if (pos_row < 0)
    {
      check_lef_moov(list, check, tmp);
      return ;
    }
  if (tmp->select == 3)
    {
      tmp->select = 2;
      while (tmp->col != pos_row || tmp->line != pos_line)
	tmp=tmp->prec;
      if (tmp->select == 0)
	tmp->select = 1;
      else
	tmp->select = 3;
    }
}
