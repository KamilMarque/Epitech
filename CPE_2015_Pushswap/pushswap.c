/*
** pushswap.c for  in /home/marque_p/rendu/CPE_2015_Pushswap
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Thu Nov 19 14:06:48 2015 Kamil Marque
** Last update Sun Nov 22 23:27:40 2015 Kamil Marque
*/

#include "my.h"

void                    rra(t_list *racine)
{
  t_list                *tmp;

  tmp = racine->prec;
  tmp->prec->next = racine;
  racine->prec = tmp->prec;
  racine->next->prec = tmp;
  tmp->next = racine->next;
  tmp->prec = racine;
  racine->next = tmp;
  write(1, "rra ", 4);
}

t_list			*rotation_la(t_list *racine)
{
  t_list		*tmp;

  tmp = racine->next;
  racine->next = racine->next->next;
  racine->next->prec = racine;
  racine->prec->next = tmp;
  tmp->prec = racine->prec;
  racine->prec = tmp;
  tmp->next = racine;
  write(1, "ra ", 3);
}

int			my_check_simple(t_list *racine)
{
  t_list		*tmp;
  t_list		*tmp2;

  tmp = racine->next;
  tmp2 = tmp;
  tmp = tmp->next;
  while (tmp != racine)
    {
      if (tmp2->val <= tmp->val)
	{
	  tmp = tmp->next;
	  tmp2 = tmp2->next;
	}
      else
	return;
    }
  return (1);
}

void			my_pushswap(t_list *racine, t_list *racine2, int ac)
{
  t_list		*tmp;
  t_list		*tmp2;

  tmp = racine->next;
  tmp2 = racine->next;
  if (my_check_simple(racine) == 1)
    return ;
  while (racine->next != racine)
    {
      tmp = racine->next;
      tmp2 = racine->next;
      my_start(racine, racine2, tmp, tmp2);
      my_mouv_lb(racine, racine2);
    }
  my_final(racine, racine2, ac);
  my_mouv_la_sp(racine , racine2);
}

int	main(int ac, char **av)
{
  t_list	*root;
  t_list	*racine2;
  int		i;

  i = 0;
  racine2 = my_create_list(racine2);
  root = my_create_list(root);
  if (ac == 1)
    {
      write(2, "Minimum 1 argument.\n", 20);
      return (0);
    }
  else
    while (++i != ac)
      ajouteravant(root, my_getnbr(av[i]));
  my_pushswap(root, racine2, ac);
  my_putchar('\n');
}
