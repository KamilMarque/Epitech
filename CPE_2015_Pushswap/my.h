/*
** my.h for  in /home/marque_p/rendu/CPE_2015_Pushswap
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Thu Nov 19 14:31:03 2015 Kamil Marque
** Last update Sun Nov 22 18:32:50 2015 Kamil Marque
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_list
{
  int		val;
  struct s_list	*prec;
  struct s_list	*next;
}		t_list;

t_list	*my_create_list(t_list *racine);
void	*ajouteravant(t_list *racine, int val);
t_list	*rotation_la(t_list *racine);
int	my_mouv_lb(t_list *racine, t_list *racine2);
void	my_mouv_la(t_list *racine, t_list *racine2);
void	my_mouv_la_sp(t_list *racine, t_list *racine2);
int	find_small(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2);
int	my_final(t_list *racine, t_list *racine2, int ac);
void	my_start(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2);
int	my_check_simple(t_list *racine);
void	my_pushswap(t_list *racine, t_list *racine2, int ac);
int	main(int ac, char **av);

#endif /* !MY_H_ */
