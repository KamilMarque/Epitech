/*
** my.h for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Jan 12 14:03:58 2016 Kamil Marque
** Last update Sun Jan 17 18:08:07 2016 Kamil Marque
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses/curses.h>
#include <term.h>

typedef struct	s_pos
{
  int		x;
  int		y;
  int		save_x;
  int		save_y;
  char		**map;
  char		**map_clean;
  int		nb_zero;
  int		cmp_zero;
  int		k;
}		t_pos;

typedef struct	s_win_place
{
  int		i;
  int		x;
  int		y;
  int		X;
  int		O;
}		t_win_place;

int     wordline(char *source, char sep);
int     contword(char *source, char sep);
char    **str_to_wordtab(char *source, char sep);
char    *my_save(char *buf, char *save);
char    *my_sokoban(char *save);
void    my_move_left(t_pos *pos);
void    my_move_left2(t_pos *pos);
void    my_move_left3(t_pos *pos);
void    my_move_left4(t_pos *pos);
void    my_move_left5(t_pos *pos);
void    my_move_left5(t_pos *pos);

#endif /* !MY_H_ */
