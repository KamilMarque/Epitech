/*
** no_options.c for  in /home/marque_p/rendu/PSU_2015_my_ls
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Fri Nov 27 16:34:33 2015 Kamil Marque
** Last update Sun Nov 29 22:38:10 2015 Kamil Marque
*/

#include "my.h"

void    my_correct_tmp(int *i, t_list *tmp)
{
  while (tmp->str[*i] == '%')
    *i = *i + 1;
}

t_list    *my_trie(t_list *racine2, t_list *racine3)
{
  t_list        *tmp;
  t_list        *tmp2;

  while (racine2->next != racine2)
    {
      tmp = racine2->next;
      tmp2 = tmp;
      my_start(racine2, racine3, tmp, tmp2);
      my_mouv_lb(racine2, racine3);
    }
  my_final(racine2, racine3);
  return (racine2);
}

void            my_no_op2(t_list *racine, t_list *racine2, int *k)
{
  t_list        *tmp;

  tmp = racine->next;
  while (tmp != racine)
    {
      if (tmp != racine->next && opendir(tmp->str) != NULL)
	my_putchar('\n');
      if (racine->next->next != racine && opendir(tmp->str) != NULL)
	{
	  my_putstr(tmp->str);
	  my_putstr(":\n");
	}
      if (opendir(tmp->str) != NULL)
	my_ls_dir(tmp, racine2);
      tmp = tmp->next;
    }
}

void            my_no_op(t_list *racine, t_list *racine2)
{
  int           k;
  t_list        *tmp;

  k = 0;
  tmp = racine->next;
  while (tmp != racine)
    {
      if (opendir(tmp->str) == NULL)
	k++;
      if (opendir(tmp->str) == NULL)
	{
	  my_putstr(tmp->str);
	  my_putchar('\n');
	}
      if (tmp->next == racine && k != 0)
      	my_putchar('\n');
      tmp = tmp->next;
    }
  my_no_op2(racine, racine2, &k);
}

void                    my_aff(t_list *racine2)
{
  t_list        *tmp;

  tmp = racine2->prec;
  while (tmp != racine2)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->prec;
    }
}
