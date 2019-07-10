/*
** my_complet_move.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Jan 16 15:15:29 2016 Kamil Marque
** Last update Sun Jan 17 17:33:16 2016 Kamil Marque
*/

#include "my.h"

void	my_move_right6(t_pos *pos)
{
  if (pos->map[pos->x][pos->y + 1] == '0' && pos->map[pos->x][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch('O');
      pos->map[pos->x][pos->y + 1] = 'O';
      pos->map[pos->x][pos->y + 2] = '0';
      move(pos->x, pos->y + 2);
      addch('X');
      move(pos->x, ++pos->y);
      addch('P');
    }
  else if (pos->map[pos->x][pos->y + 1] != '#')
    {
      move(pos->x, pos->y);
      addch(' ');
      pos->map[pos->x][pos->y + 1] = 'O';
      pos->map[pos->x][pos->y + 2] = '0';
      move(pos->x, pos->y + 2);
      addch('X');
      move(pos->x, ++pos->y);
      addch('P');
    }
}

void	my_move_left6(t_pos *pos)
{
  if (pos->map[pos->x][pos->y - 1] == '0' && pos->map[pos->x][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch('O');
      pos->map[pos->x][pos->y - 1] = 'O';
      pos->map[pos->x][pos->y - 2] = '0';
      move(pos->x, pos->y - 2);
      addch('X');
      move(pos->x, --pos->y);
      addch('P');
    }
  else if (pos->map[pos->x][pos->y - 1] != '#')
    {
      move(pos->x, pos->y);
      addch(' ');
      pos->map[pos->x][pos->y - 1] = 'O';
      pos->map[pos->x][pos->y - 2] = '0';
      move(pos->x, pos->y - 2);
      addch('X');
      move(pos->x, --pos->y);
      addch('P');
    }
}

void	my_move_up6(t_pos *pos)
{
  if (pos->map[pos->x - 1][pos->y] == '0' && pos->map[pos->x][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch('O');
      pos->map[pos->x - 1][pos->y] = 'O';
      pos->map[pos->x - 2][pos->y] = '0';
      move(pos->x - 2, pos->y);
      addch('X');
      move(--pos->x, pos->y);
      addch('P');
    }
  else
    {
      move(pos->x, pos->y);
      addch(' ');
      pos->map[pos->x - 1][pos->y] = 'O';
      pos->map[pos->x - 2][pos->y] = '0';
      move(pos->x - 2, pos->y);
      addch('X');
      move(--pos->x, pos->y);
      addch('P');
    }
}

void	my_move_down6(t_pos *pos)
{
  if (pos->map[pos->x + 1][pos->y] == '0' && pos->map[pos->x][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch('O');
      pos->map[pos->x + 1][pos->y] = 'O';
      pos->map[pos->x + 2][pos->y] = '0';
      move(pos->x + 2, pos->y);
      addch('X');
      move(++pos->x, pos->y);
      addch('P');
    }
  else
    {
      move(pos->x, pos->y);
      addch(' ');
      pos->map[pos->x + 1][pos->y] = 'O';
      pos->map[pos->x + 2][pos->y] = '0';
      move(pos->x + 2, pos->y);
      addch('X');
      move(++pos->x, pos->y);
      addch('P');
    }
}

void    my_direct_check_size(t_pos *pos, char *save, int ch, int c)
{
  int   x;
  int   y;
  int   col;
  int   row;

  x = my_strlen(pos->map[0]);
  y = contword(save, '\n');
  getmaxyx(stdscr, row, col);
  if (x > col || y > row)
    {
      pos->k = 1;
      clear();
      printw("%s\n", "Fenetre trop petite\n");
    }
  else
    my_direct_check_size2(pos, save, ch);
}
