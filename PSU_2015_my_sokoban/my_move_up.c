/*
** my_move_up.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Jan 16 14:07:19 2016 Kamil Marque
** Last update Sun Jan 17 17:34:08 2016 Kamil Marque
*/

#include "my.h"

void    my_move_up2(t_pos *pos)
{
  if (pos->map[pos->x][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch('O');
      move(--pos->x, pos->y);
      addch('P');
    }
  else
    {
      move(pos->x, pos->y);
      addch(' ');
      move(--pos->x, pos->y);
      addch('P');
    }
}

void    my_move_up3(t_pos *pos)
{
  if (pos->map[pos->x][pos->y] == 'O')
    {
      pos->map[pos->x - 1][pos->y] = ' ';
      pos->map[pos->x - 2][pos->y] = 'X';
      move(pos->x, pos->y);
      addch('O');
      move(--pos->x, pos->y);
      addch('P');
      move(pos->x - 1, pos->y);
      addch('X');
    }
  else
    {
      pos->map[pos->x - 1][pos->y] = ' ';
      pos->map[pos->x - 2][pos->y] = 'X';
      move(pos->x - 2, pos->y);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(--pos->x, pos->y);
      addch('P');
    }
}

void    my_move_up4(t_pos *pos)
{
    {
      pos->cmp_zero--;
      pos->map[pos->x - 1][pos->y] = 'O';
      pos->map[pos->x - 2][pos->y] = 'X';
      move(pos->x - 2, pos->y);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(--pos->x, pos->y);
      addch('P');
      if (pos->map[pos->x + 1][pos->y] == 'O')
	{
	  move(pos->x + 1, pos->y);
	  addch('O');
	}
    }
}

void    my_move_up5(t_pos *pos)
{
  if (pos->map[pos->x - 1][pos->y] == 'X' &&
      pos->map[pos->x - 2][pos->y] == 'O')
    {
      pos->map[pos->x - 1][pos->y] = ' ';
      pos->map[pos->x - 2][pos->y] = '0';
      my_check_final_add(pos);
      move(pos->x - 2, pos->y);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(--pos->x, pos->y);
      addch('P');
    }
  else if (pos->map[pos->x - 1][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch(' ');
      move(--pos->x, pos->y);
      addch('P');
    }
}

void    my_move_up(t_pos *p)
{
  if (p->map[p->x - 1][p->y] == ' ' || p->map[p->x - 1][p->y] == 'O')
    my_move_up2(p);
  else if (p->map[p->x - 1][p->y] == 'X' && p->map[p->x - 2][p->y] == ' ')
    my_move_up3(p);
  else if ((p->map[p->x - 1][p->y] == 'X' && p->map[p->x - 2][p->y] == 'O')
	   || (p->map[p->x - 1][p->y] == 'O'))
    my_move_up5(p);
  else if (p->map[p->x - 1][p->y] == '0')
    {
      if (p->map[p->x - 2][p->y] == ' ')
	my_move_up4(p);
      else if (p->map[p->x - 2][p->y] == 'O')
	my_move_up6(p);
    }
}
