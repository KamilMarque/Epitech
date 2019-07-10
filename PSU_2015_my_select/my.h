/*
** my.h for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Feb 16 09:38:50 2016 Kamil Marque
** Last update Wed Feb 24 14:37:07 2016 Kamil Marque
*/

#ifndef MY_H_
# define MY_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <ncurses/curses.h>
# include <term.h>
# include "lib/my/my_strdup.h"

typedef struct  s_list
{
  char		*str;
  struct s_list *prec;
  struct s_list *next;
  int            select;
  int            col;
  int            line;
}               t_list;

typedef struct	s_check
{
  int		 nb_word_return;
  int            pos_line;
  int            nb_elem;
  int            pos_curs;
  int            col_size;
}		t_check;

t_list                  *my_create_list(t_list *racine);
void                    *ajouteravant(t_list *racine, char *str);

#endif /* !MY_H_ */
