/*
** my_check_map.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Jan 16 15:47:15 2016 Kamil Marque
** Last update Sat Jan 16 20:30:56 2016 Kamil Marque
*/

#include "my.h"

char		*my_save(char *buf, char *save)
{
  int		cpt1;
  int		cpt2;
  char		*tmp;

  cpt1 = 0;
  cpt2 = 0;
  if (save != NULL)
    {
      if ((tmp = malloc(sizeof(char) * (my_strlen(buf)
					+ my_strlen(save) + 1))) == NULL)
	return (NULL);
      while (save[cpt1] != 0)
	tmp[cpt2++] = save[cpt1++];
      free(save);
    }
  else    if ((tmp = malloc(sizeof(char) * (my_strlen(buf) + 1))) == NULL)
    return (NULL);
  cpt1 = 0;
  while (buf[cpt1] != 0)
    tmp[cpt2++] = buf[cpt1++];
  tmp[cpt2] = 0;
  return (tmp);
}

int		my_check_map(char **map, char *save, int x, int y)
{
  int		i;
  int		nb_line;

  nb_line = contword(save, '\n');
  i = my_strlen(map[x]);
  while (map[x])
    {
      while (map[x][y])
	{
	  if (map[x][y] != 0 && map[x][y] != '#' && map[x][y] != 'O'
	      && map[x][y] != 'X' && map[x][y] != 'P' && map[x][y] != ' ')
	    return (-1);
	  if (map[0][y] != '#' || map[x][i - 1] != '#')
	    return (-1);
	  if (map[nb_line - 1][y] != '#')
	    return (-1);
	  y++;
	}
      if (y != i)
	return (-1);
      y = 0;
      if (map[x++][0] != '#')
	return (-1);
    }
}

void		my_init(int *X, int *i, int *x, char *save)
{
  *X = 0;
  *x = 0;
  *i = contword(save, '\n');
}

void		my_wood_of_if(t_pos *pos, t_win_place *win_place, int *cpt)
{
  if (pos->map[win_place->x][win_place->y] == 'P')
    {
      pos->x = win_place->x;
      pos->y = win_place->y;
      *cpt = *cpt + 1;
    }
  if (pos->map[win_place->x][win_place->y] == 'O')
    win_place->O++;
  if (pos->map[win_place->x][win_place->y] == 'X')
    win_place->X++;
}

int		my_check_last_line(char *save, int cpt, t_pos *pos)
{
  t_win_place   more_place;

  more_place.O = 0;
  my_init(&more_place.X, &more_place.i, &more_place.x, save);
  while (pos->map[more_place.x])
    {
      more_place.y = 0;
      while (pos->map[more_place.x][more_place.y])
	{
	  my_wood_of_if(pos, &more_place, &cpt);
	  more_place.y++;
	}
      more_place.x++;
    }
  pos->nb_zero = more_place.O;
  pos->cmp_zero = 0;
  if (more_place.X != more_place.O || cpt > 1 ||
      cpt == 0 || more_place.X == 0 || more_place.O == 0)
    return (-1);
}
