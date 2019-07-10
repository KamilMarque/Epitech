/*
** getnextline.h for  in /home/henry_g/rendu/get_next_line/include
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sun Jan  3 00:03:05 2016 Clément Henry
** Last update Sun May 29 22:50:44 2016 kamil
*/

#ifndef GETNEXTLINE_H_
# define GETNEXTLINE_H_

#ifndef READ_SIZE
# define READ_SIZE (100)
#endif /* !READ_SIZE */

typedef struct	s_line
{
  int		i;
  int		c;
}		t_line;

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*get_next_line(const int fd);
int     return_min_val(char **tab);
int     verf_courb2(char **tab);
int     verf_courb(char **tab);
int     algo(char **tab);
int     init(int *left, int *right, int *res, char **tab);
int     end_tab(char **tab);
int     start_tab(char **tab);
void    go_right(int left, int right, int res);
void    go_left(int left, int right, int res);
int     contword(char *str, char sep);
int     my_strlen_tab(char *str, char sep);
char    **str_to_wordtab(char *str, char sep);
int	my_strlen(char *str);
void	my_putstr(char *str);
int	my_find_val(char **tab);
int	go_my_litle_car(char **tab);
int     my_getnbr(char *str);

#endif /* !GETNEXTLINE_H_ */
