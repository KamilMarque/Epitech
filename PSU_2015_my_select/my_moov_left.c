/*
** my_moov_left.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb 24 15:31:20 2016 Kamil Marque
** Last update Wed Feb 24 19:34:37 2016 Kamil Marque
*/

#include "my.h"

void		my_moov_left(t_list *list, t_check *check, int pos_line)
{
  t_list	*tmp;
  int		pos_row;

  tmp = list->next;
  while (tmp->select != 1 && tmp->select != 3)
    tmp = tmp->next;
  if (tmp->select == 1)
    {
      pos_line = tmp->line;
      pos_row = tmp->col - check->col_size - 4;
      if (pos_row < 0)
	{
	  check_lef_moov(list, check, tmp);
	  return ;
	}
      tmp->select = 0;
      while (tmp->col != pos_row || tmp->line != pos_line)
	tmp=tmp->prec;
      if (tmp->select == 0)
	tmp->select = 1;
      else
	tmp->select = 3;
    }
  else
    my_moov_left2(list, check, tmp);
}

void		my_moov_right1_5(t_list *list, t_check *check, t_list *tmp)
{
  if (tmp->select == 0)
    tmp->select = 1;
  else
    tmp->select = 3;
}

int		my_moov_right2(t_list *list, t_check *check, t_list *tmp)
{
  int		pos_line;
  int		pos_row;
  t_list	*tmp2;

  pos_line = tmp->line;
  pos_row = tmp->col + check->col_size + 4;
  tmp2 = tmp;
  if (tmp->select == 3)
    {
      tmp->select = 2;
      while (tmp->col != pos_row || tmp->line != pos_line)
	  {
	    tmp=tmp->next;
	    if (tmp == tmp2)
	      {
		if (list->next->select == 2)
		  list->next->select = 3;
		else
		  list->next->select = 1;
		return ;
	      }
	  }
      my_moov_right1_5(list, check, tmp);
    }
}

void		init_moov(t_list *list, t_check *check, t_list *tmp, t_list *tmp2)
{
  if (list->next->select == 2)
    list->next->select = 3;
  else
    list->next->select = 1;
}

void		my_moov_right(t_list *list, t_check *check, int pos_line, int pr)
{
  t_list	*tmp;
  t_list	*tmp2;

  tmp = list->next;
  while (tmp->select != 1 && tmp->select != 3)
    tmp = tmp->next;
  tmp2 = tmp;
  if (tmp->select == 1)
    {
      tmp->select = 0;
      pos_line = tmp->line;
      pr = tmp->col + check->col_size + 4;
      while (tmp->col != pr || tmp->line != pos_line)
	{
	  tmp=tmp->next;
	  if (tmp == tmp2)
	    {
	      init_moov(list, check, tmp, tmp2);
	      return ;
	    }
	}
      my_moov_right1_5(list, check, tmp);
    }
  else
    my_moov_right2(list, check, tmp);
}
