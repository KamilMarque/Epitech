/*
** my_mouv_left.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Jan 16 02:21:58 2016 Kamil Marque
** Last update Sun Jan 17 17:33:45 2016 Kamil Marque
*/

#include "my.h"

void	my_move_left2(t_pos *pos)
{
  if (pos->map[pos->x][pos->y - 2] == ' ')
    {
      pos->cmp_zero--;
      pos->map[pos->x][pos->y - 1] = 'O';
      pos->map[pos->x][pos->y - 2] = 'X';
      move(pos->x, pos->y - 2);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, --pos->y);
      addch('P');
    }
  if (pos->map[pos->x][pos->y + 1] == 'O')
    {
      move(pos->x, pos->y + 1);
      addch('O');
    }
}

void	my_move_left3(t_pos *pos)
{
  if (pos->map[pos->x][pos->y - 1] == 'O')
    {
       move(pos->x, pos->y);
       addch(' ');
       move(pos->x, --pos->y);
       addch('P');
    }
  else if (pos->map[pos->x][pos->y - 2] == 'O')
    my_move_left6(pos);
}

void	my_move_left4(t_pos *pos)
{
  if (pos->map[pos->x][pos->y] == 'O')
    {
      pos->map[pos->x][pos->y - 1] = ' ';
      pos->map[pos->x][pos->y - 2] = 'X';
      move(pos->x, pos->y);
      addch('O');
      move(pos->x, --pos->y);
      addch('P');
      move(pos->x, pos->y - 1);
      addch('X');
    }
  else
    {
      pos->map[pos->x][pos->y - 1] = ' ';
      pos->map[pos->x][pos->y - 2] = 'X';
      move(pos->x, pos->y - 2);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, --pos->y);
      addch('P');
    }
}

void	my_move_left5(t_pos *pos)
{
  if (pos->map[pos->x][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch('O');
      move(pos->x, --pos->y);
      addch('P');
    }
  else
    {
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, --pos->y);
      addch('P');
    }
}

void    my_move_left(t_pos *p)
{
  if (p->map[p->x][p->y - 1] == ' ' || p->map[p->x][p->y - 1] == 'O')
    my_move_left5(p);
  else if (p->map[p->x][p->y - 1] == 'X' && p->map[p->x][p->y - 2] == 'O')
    {
      p->map[p->x][p->y - 1] = ' ';
      p->map[p->x][p->y - 2] = '0';
      my_check_final_add(p);
      move(p->x, p->y - 2);
      addch('X');
      move(p->x, p->y);
      addch(' ');
      move(p->x, --p->y);
      addch('P');
    }
  else if (p->map[p->x][p->y - 1] == '0' && p->map[p->x][p->y - 2] == ' ')
    my_move_left2(p);
  else if (p->map[p->x][p->y - 1] == 'O' || (p->map[p->x][p->y - 2] == 'O'))
    my_move_left3(p);
  else if (p->map[p->x][p->y - 1] == 'X' && p->map[p->x][p->y - 2] == ' ')
    my_move_left4(p);
}
