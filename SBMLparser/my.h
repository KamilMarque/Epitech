/*
** my.h for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 13:42:28 2016 kamil
** Last update Wed Jun 15 10:22:10 2016 kamil
*/

#ifndef MY_H_
# define MY_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct  s_list
{
  char          *str;
  char		**tab_before;
  char		**tab_after;
  struct s_list *prec;
  struct s_list *next;
}               t_list;

void            *ajouteravant(t_list *racine, char *str, int cpt, char *save);
void            my_putstr(char *str);
void            my_putstr_error(char *str);
void            my_help();
void            aff_spacies(t_list *list);
void		my_tab_swap(char **tab, int j);
int             my_strlen(char *str);
int		contword(char *str, char sep);
int		my_strlen_tab(char *str, char sep);
int             my_compare(char *s1, char *s2);
int             find_option_i(char *str, t_list *list);
int             find_option_i2(char *str, t_list *list);
int             pars_start(char **av, t_list *list);
int             my_com_tri(char *str, char *str2);
char            *my_save(char *buf, char *save);
char		*my_alloc_la(t_list *list, char *str);
char		**str_to_wordtab(char *str, char sep);
t_list          *my_create_list(t_list *racine);
t_list          *my_tri_list(t_list *list);

#endif /* !MY_H_ */
