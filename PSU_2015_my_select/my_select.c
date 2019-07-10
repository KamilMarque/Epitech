/*
** my_select.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Feb 16 10:41:41 2016 Kamil Marque
** Last update Thu Feb 25 15:59:15 2016 Kamil Marque
*/

#include "my.h"

void		my_check_move(int ch, t_list *list, t_check *check)
{
  if (ch == KEY_UP)
    my_moov_up(list, check);
  else if (ch == KEY_DOWN)
    my_moov_down(list, check);
  else if (ch == 32)
    my_space(list, check);
  else if (ch == KEY_BACKSPACE ||  ch == KEY_DC)
    my_backspace(list, check);
  else if (ch == KEY_LEFT)
    my_moov_left(list, check, 0);
  else if (ch == KEY_RIGHT)
    my_moov_right(list, check, 0, 0);
  else if (ch == 27)
    {
      endwin();
      exit(0);
    }
}

void		my_final_aff(t_list *list, t_check *check)
{
  t_list	*tmp;
  int		cpt;

  cpt = 0;
  tmp = list->next;
  while (tmp != list)
    {
      if (tmp->select == 2 || tmp->select == 3)
	{
	  my_putstr(tmp->str);
	  if (cpt + 1 < check->nb_word_return)
	    my_putchar(' ');
	  cpt++;
	}
      tmp = tmp->next;
    }
}

void		my_select2(t_list *list, t_check *check, t_list *tmp)
{
  check->col_size = col_size(list);
  calc_col(list, check);
  clear();
  while (tmp != list)
    {
      if (tmp->select == 1)
	attron(A_UNDERLINE);
      else if (tmp->select == 3)
	{
	  attron(A_UNDERLINE);
	  attron(A_REVERSE);
	}
      else if (tmp->select == 2)
	  attron(A_REVERSE);
      mvprintw(tmp->line, tmp->col, "%s", tmp->str);
      attroff(A_UNDERLINE);
      attroff(A_REVERSE);
      tmp = tmp->next;
    }
  check_direct_size(check);
  tmp = tmp->next;
}

void		my_select(t_list *list, t_check *check)
{
  int		ch;
  int		x;
  t_list	*tmp;

  tmp = list->next;
  newterm(NULL, stdin, stdin);
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  noecho();
  refresh();
  tmp->select = 1;
  while (ch != 10)
    {
      my_select2(list, check, tmp);
      ch = getch();
      my_check_move(ch, list, check);
    }
  endwin();
  my_final_aff(list, check);
}

int		main(int ac, char **av)
{
  int		i;
  t_list	*list;
  t_check	*check;

  i = 1;
  check->nb_elem = ac - 1;
  check->nb_word_return = 0;
  list = my_create_list(list);
  if (ac == 1)
    return (0);
  while (i != ac)
    ajouteravant(list, av[i++]);
  my_select(list, check);
}
