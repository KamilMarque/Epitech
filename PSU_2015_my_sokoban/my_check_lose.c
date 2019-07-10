/*
** my_check_lose.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Jan 16 22:47:20 2016 Kamil Marque
** Last update Sat Jan 16 23:45:43 2016 Kamil Marque
*/

#include "my.h"

int	my_boucle_up(t_pos *pos, char *save)
{
  int	x;
  int	i;
  int	y;

  x = 0;
  y = 0;
  while (pos->map[x])
    {
      if (pos->map[x][pos->y] == 'O')
	return (0);
      x++;
    }
  while (pos->map[pos->x][y] != 0)
    {
      if (pos->map[pos->x - 1][y++] == 'O')
	return (0);
    }
  return (1);
}

void	test(t_pos *pos, char *save)
{
  if (pos->map[pos->x - 1][pos->y] == 'X')
    {
      if (pos->map[pos->x - 2][pos->y] == '#')
	if (my_boucle_up(pos, save) == 1)
	  {
	    endwin();
	    exit (1);
	  }
    }
}
