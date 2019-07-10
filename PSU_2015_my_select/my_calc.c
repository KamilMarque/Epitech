/*
** my_calc.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb 24 15:05:07 2016 Kamil Marque
** Last update Wed Feb 24 15:16:20 2016 Kamil Marque
*/

#include "my.h"

int             col_size(t_list *list)
{
  int           save;
  t_list        *tmp;

  save = my_strlen(list->next->str);
  tmp = list->next;
  while (tmp != list)
    {
      if (my_strlen(tmp->str) > save)
	save = my_strlen(tmp->str);
      tmp = tmp->next;
    }
  return (save);
}

void             calc_col(t_list *list, t_check *check)
{
  int           line;
  int           col;
  t_list        *tmp;
  int           max_win_col;
  int           max_win_row;

  tmp = list->next;
  list->line = 0;
  list->col = 0;
  line = 0;
  col = 0;
  getmaxyx(stdscr, max_win_row, max_win_col);
  while (tmp != list)
    {
      if (line > max_win_row - 1)
	{
	  col = col + check->col_size + 4;
	  line = 0;
	}
      tmp->line = line;
      tmp->col = col;
      tmp = tmp->next;
      line++;
    }
}

void		check_direct_size(t_check *check)
{
  int		win_col;
  int		win_row;
  int		nb;

  getmaxyx(stdscr, win_row, win_col);
  nb = check->nb_elem / win_row + 1;
  nb = nb * (check->col_size + 4);
  if (nb > win_col)
    {
      clear();
      printw("Window's size is too small\n");
    }
}
