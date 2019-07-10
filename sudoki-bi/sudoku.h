/*
** sudoku.h for  in /home/henry_g/sudoku-bi
** 
** Made by Clément Henry
** Login   <henry_g@epitech.net>
** 
** Started on  Sun Feb 28 01:02:57 2016 Clément Henry
** Last update Sun Feb 28 19:45:13 2016 Kamil Marque
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_list
{
  char		nb;
  int		pos_x;
  int		pos_y;
  int           val;
  struct s_list *prec;
  struct s_list *next;
}		t_list;

void	my_sudoku(char **av);
int	check_map(char **tab);
int	my_check_mid(char **tab, int *x, int *y);
t_list  *my_create_list(t_list *racine);
void    *ajouteravant(t_list *racine, int val, int x, int y);
void    fill_map2(t_list *list, t_list *list2, char **tmp);
char    *my_save(char *buf, char *save, int count);
char    **new_tab(char **map, int *i);
char	**false_map(char **amp);
int     my_check_col(char **tab, int y);
int     my_check_line(char **tab, int x);
int     my_check_tab(char **tab, int x, int y);
int     my_final_val(char **tab, int x, int y);
t_list  *my_att_pos(char **tab);
int	horizontal(char **map, int i, char nb);
int	vertical(char **map, int j, char nb);
int	square(char **map, char nb, int i, int j);
t_list	*solve_it2(char **map, t_list *tmp, int *cpt);
char	**solve_it(char **map, t_list *list);
char	**nw_tab(char **tab_map);
char	**fill_map(t_list *list, t_list *list2);
int	how_alloc(char *str, char what, int index);
void	print_my_tab(char **tab);
int	count_words(char *str, char what);
void	initialise(int *i, int *j);
char	**my_str_to_wordtab(char *str, char what);
void    my_mouv_lb(t_list *racine, t_list *racine2);
void    rotation_la(t_list *racine);
void    my_tri_list2(t_list *list, t_list *list2);
t_list  *my_tri_list(t_list *list, t_list *list2);

#endif /* !SUDOKU_H_ */
