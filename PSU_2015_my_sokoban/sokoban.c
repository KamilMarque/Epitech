/*
** sokoban.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Mon Jan 11 17:43:38 2016 Kamil Marque
** Last update Sun Jan 17 00:37:05 2016 Kamil Marque
*/

#include "my.h"

void	my_check_final_add(t_pos *pos)
{
  pos->cmp_zero++;
  if (pos->cmp_zero == pos->nb_zero)
    {
      endwin();
      exit (0);
    }
}

void	my_check_move(int ch, t_pos *pos, char *save)
{
  if (ch == KEY_LEFT)
    my_move_left(pos);
  if (ch == KEY_RIGHT)
    my_move_right(pos);
  if (ch == KEY_UP)
    my_move_up(pos, save);
  if (ch == KEY_DOWN)
    my_move_down(pos);
  else
    return ;
}

void	my_init_curs(t_pos *pos, int x)
{
  initscr();
  cbreak();
  curs_set(0);
  keypad(stdscr, TRUE);
  noecho();
  refresh();
  while (pos->map[x])
    printw("%s\n", pos->map[x++]);
  pos->map[pos->x][pos->y] = ' ';
  pos->save_x = pos->x;
  pos->save_y = pos->y;
}

char	*my_sokoban(char *save)
{
  t_pos	pos;
  int	x;
  int	ch;

  x = 0;
  ch = 0;
  pos.map = str_to_wordtab(save, '\n');
  if ((my_check_map(pos.map, save, 0, 0) == -1) ||
      (my_check_last_line(save, 0, &pos) == -1))
   exit (1);
  my_init_curs(&pos, x);
  while (ch != 'q')
    {
      my_direct_check_size(&pos, save, ch, 0);
      ch = getch();
      my_check_move(ch, &pos, save);
    }
  endwin();
}
