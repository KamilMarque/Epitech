/*
** my.h for  in /home/marque_p/rendu/CPE_2015_BSQ
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Dec  2 11:37:54 2015 Kamil Marque
** Last update Sat Dec 19 12:47:09 2015 Kamil Marque
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_square
{
  int	size_square;
  int	pos_x;
  int	pos_y;
  int	x;
  int	y;
}		t_square;

int     wordline(char *source, char sep);
int     contword(char *source, char sep);
char    **str_to_wordtab(char *source, char sep);
char    *my_save(char *buf, char *save);
int	my_check_square(t_square *square, char **tab, int y, int x);
void    my_no_square(t_square *square, char **tab);
void    my_aff_map(t_square *square, char **tab);
void    my_square(t_square *square, char **tab);
int    my_algo(char **tab);
void    my_bsq(char *str);

#endif /*MY_H_*/
