/*
** my_mouv_right.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Jan 16 02:48:39 2016 Kamil Marque
** Last update Sun Jan 17 17:30:51 2016 Kamil Marque
*/

#include "my.h"

void	my_mouv_right2(t_pos *pos)
{
  if (pos->map[pos->x][pos->y] == 'O')
    {
      move(pos->x, pos->y);
      addch('O');
      move(pos->x, ++pos->y);
      addch('P');
    }
  else
    {
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, ++pos->y);
      addch('P');
    }
}

void	my_mouv_right3(t_pos *pos)
{
  if (pos->map[pos->x][pos->y] == 'O')
    {
      pos->map[pos->x][pos->y + 1] = ' ';
      pos->map[pos->x][pos->y + 2] = 'X';
      move(pos->x, pos->y);
      addch('O');
      move(pos->x, ++pos->y);
      addch('P');
      move(pos->x, pos->y + 1);
      addch('X');
    }
  else
    {
      pos->map[pos->x][pos->y + 1] = ' ';
      pos->map[pos->x][pos->y + 2] = 'X';
      move(pos->x, pos->y + 2);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, ++pos->y);
      addch('P');
    }
}

void	my_mouv_right4(t_pos *pos)
{
  if (pos->map[pos->x][pos->y + 2] == ' ')
    {
      pos->cmp_zero--;
      pos->map[pos->x][pos->y + 1] = 'O';
      pos->map[pos->x][pos->y + 2] = 'X';
      move(pos->x, pos->y + 2);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, ++pos->y);
      addch('P');
    }
  if (pos->map[pos->x][pos->y - 1] == 'O')
    {
      move(pos->x, pos->y - 1);
      addch('O');
    }
}

void	my_mouv_right5(t_pos *pos)
{
  if (pos->map[pos->x][pos->y + 1] == 'X' &&
      pos->map[pos->x][pos->y + 2] == 'O')
    {
      pos->map[pos->x][pos->y + 1] = ' ';
      pos->map[pos->x][pos->y + 2] = '0';
      my_check_final_add(pos);
      move(pos->x, pos->y + 2);
      addch('X');
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, ++pos->y);
      addch('P');
    }
  else if (pos->map[pos->x][pos->y + 1] == 'O')
    {
      move(pos->x, pos->y);
      addch(' ');
      move(pos->x, ++pos->y);
      addch('P');
    }
}

void    my_move_right(t_pos *pos)
{
  if (pos->map[pos->x][pos->y + 1] == ' ' ||
      pos->map[pos->x][pos->y + 1] == 'O')
    my_mouv_right2(pos);
  else if (pos->map[pos->x][pos->y + 1] == 'X' &&
	   pos->map[pos->x][pos->y + 2] == ' ')
    my_mouv_right3(pos);
  else if ((pos->map[pos->x][pos->y + 1] == 'X' &&
	    pos->map[pos->x][pos->y + 2] == 'O') ||
	   (pos->map[pos->x][pos->y + 1] == 'O'))
    my_mouv_right5(pos);
  else if (pos->map[pos->x][pos->y + 1] == '0' &&
	   pos->map[pos->x][pos->y + 2] == ' ')
    my_mouv_right4(pos);
  else if (pos->map[pos->x][pos->y + 2] == 'O')
    my_move_right6(pos);
}
