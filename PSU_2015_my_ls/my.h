/*
** my.h for  in /home/marque_p/rendu/PSU_2015_my_ls
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Nov 25 17:05:43 2015 Kamil Marque
** Last update Sun Nov 29 21:06:25 2015 Kamil Marque
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

typedef struct		s_check
{
  int			l;
  int			r;
  int			d;
  int			t;
  int			big_r;
}			t_check;

typedef struct		s_list
{
  char			*str;
  struct s_list		*next;
  struct s_list		*prec;
}			t_list;

t_list	*my_create_list(t_list *racine);
void    my_correct_tmp(int *i, t_list *tmp);
t_list  *my_trie(t_list *racine2, t_list *racine3);
void	*ajouterapres(t_list *element, char *array);
t_list	*rotation_la(t_list *racine);
int	my_mouv_lb(t_list *racine, t_list *racine2);
t_list	*rotation_la(t_list *racine);
void	my_aff(t_list *racine2);
void	my_basic_ls();
int	my_options(char *array, t_check *chack);
int	my_save(int ac, char **av, t_list *racine, t_check *check);
int     my_final(t_list *racine, t_list *racine2);
int     find_small(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2);
void    my_pass(int *i, t_list *tmp, t_list *tmp2);
float	id_carac_tmp(int *i, t_list *tmp);
void    my_start(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2);
int     my_save(int ac, char **av, t_list *racine, t_check *check);
void    ini_check(t_check *check);
int     my_ls_dir(t_list *racine, t_list *racine2);
int     right(mode_t st_mode);
void    my_d(t_list *racine, t_check *check);
void	my_basic_ls(t_list *racine2, t_list *racine3);
int	my_options(char *array, t_check *check);
int	my_check_correct_option(char c);
void    my_r(t_list *racine, t_check *check);
void	my_no_op2(t_list *racine, t_list *racine2, int *k);
void	my_no_op(t_list *racine, t_list *racine2);
