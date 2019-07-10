/*
** my.h for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Mon Mar 14 16:09:04 2016 Kamil Marque
** Last update Sun Apr  3 18:24:59 2016 kamil
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "lib/my/my.h"
#include "lib/my/my_strdup.h"

typedef struct	s_mini
{
  char	*my_d;
  char  **before;
  char  **after;
  char	**valid_tab;
  char	**tab_path;
  char	*good_path;
  char	*path;
  char	*my_user;
  char	**mult;
  char	*cd_less;
}		t_mini;

int	my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strdup(char *src);
int	contword(char *str, char sep);
int	my_strlen_tab(char *str, char sep);
char	**str_to_wordtab(char *str, char sep);
char    *my_save(char *buf, char *save, int count);
int     my_check(char *save);
int     my_init(int *j, int *i, char *save, char *res);
char    *get_next_line(const int fd);
void    my_aff_tab(t_mini *mini);
int     my_calc_env(char **env);
int     my_sp_strlen(char *str, char sep);
int     my_strlen_end(char *str);
char    *my_cut_env(char **env, t_mini *mini);
char    *my_cut_env_end(char **env, t_mini *mini);
char    *my_valid_arg(char *str, t_mini *mini);
int     find_my_path(t_mini *mini);
void    my_path_default(t_mini *mini);
char    *find_my_path2(t_mini *m);
char    *my_acces(t_mini *mini);
void    my_fork(t_mini *mini, char **env);
int     my_check_cmp(char *s1, char *s2);
char    *my_cd_user(t_mini *mini);
int     my_check_nb(t_mini *mini);
char    *my_add_env2(t_mini *mini, char **tmp, char **tmp2, int len);
char    *my_add_env(t_mini *mini);
int     my_setenv(t_mini *mini);
char    *my_supp_env_tab2(t_mini *mini, char **tmp, char **tmp2, int len);
char    *my_supp_env_tab(t_mini *mini, int len, int i, int j);
void    my_supp_env(t_mini *mini);
void    my_execu(t_mini *mini, char **env);
int     my_check_arg2(t_mini *mini, char **env);
int	my_check_arg(t_mini *mini, char **env);

#endif /* !MY_H_ */
