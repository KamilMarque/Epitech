/*
** my.h for  in /home/marque_p/rendu/CPE_2015_Allum1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Feb 16 14:38:10 2016 Kamil Marque
** Last update Sun Feb 21 00:55:17 2016 Kamil Marque
*/

#ifndef MY_H_
# define MY_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_allum
{
  int		*tab;
  int		line;
  int		matches;
  int		my_diff;
  int		line_c;
  int		tmp_c;
  char		*matches_c;
  char		*str;
}		t_allum;

char    *my_save(char *buf, char *save, int count);
int     my_check(char *save);
int     my_init(int *j, int *i, char *save, char *res);
char	*get_next_line(const int fd);
int	*my_create_tab(int *tab);
int     my_aff2(t_allum *allum, int *k, int *i, int j);
void    my_aff(t_allum *allum);
void    my_allum(t_allum *allum);
int     my_getnbr(char *str);
int     my_check_arg(char *line);
char    *my_check_line(t_allum *allum);
char    *my_check_matches(char *line, t_allum *allum);
int     my_check_win(t_allum *allum);
int     my_xor(t_allum *allum);
int     my_final_check(t_allum *allum);
void    my_final_mouv2(t_allum *allum, int i, int nb_matches);
void    my_final_mouv(t_allum *allum);
void    my_spec_mouv(t_allum *allum);
int     my_ia_moov(t_allum *allum);
void    my_ai(t_allum *allum);
int     my_comm(t_allum *allum);

#endif /* !MY_H_ */
