/*
** my_complet_move2.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Jan 17 12:55:32 2016 Kamil Marque
** Last update Sun Jan 17 13:13:07 2016 Kamil Marque
*/

#include "my.h"

void	my_direct_check_size3(t_pos *pos, char *save, int ch)
{
  int	c;

  if (ch == 32)
   {
     c = 0;
     clear();
     pos->map = str_to_wordtab(save, '\n');
     while (pos->map[c])
       printw("%s\n", pos->map[c++]);
     pos->map[pos->save_x][pos->save_y] = ' ';
     pos->cmp_zero = 0;
     pos->x = pos->save_x;
     pos->y = pos->save_y;
   }
}

void	my_direct_check_size2(t_pos *pos, char *save, int ch)
{
  int	c;
  int	col;
  int	row;
  int   x;
  int   y;

  x = my_strlen(pos->map[0]);
  y = contword(save, '\n');
  if (pos->k == 1)
    {
      c = 0;
      clear();
      refresh();
      pos->map[pos->x][pos->y] = 'P';
      while (pos->map[c])
	printw("%s", pos->map[c++]);
      pos->k = 0;
      pos->map[pos->x][pos->y] = ' ';
    }
  my_direct_check_size3(pos, save, ch);
}
