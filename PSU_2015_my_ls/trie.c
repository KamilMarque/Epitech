/*
** trie.c for  in /home/marque_p/rendu/PSU_2015_my_ls
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Fri Nov 27 12:06:48 2015 Kamil Marque
** Last update Fri Nov 27 16:43:00 2015 Kamil Marque
*/

#include "my.h"

int     my_final(t_list *racine, t_list *racine2)
{
  int   i;

  i = 1;
  if (racine->next == racine)
    while (racine2->next != racine2)
      my_mouv_la(racine , racine2);
}

int     find_small(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2)
{
  if (tmp == racine)
    {
      while (tmp != tmp2)
	{
	  rotation_la(racine);
	  tmp = racine->next;
	}
      return (1);
    }
  return (0);
}

void    my_pass(int *i, t_list *tmp, t_list *tmp2)
{
  if (tmp2->str[*i] == tmp->str[*i])
    while (tmp2->str[*i] == tmp->str[*i]
	   && (tmp->str[*i] != 0 || tmp2->str[*i] != 0))
      *i = *i + 1;
  while (tmp->str[*i] == tmp2->str[*i] + 32)
    *i = *i + 1;
  while (tmp2->str[*i] == tmp->str[*i] + 32)
    *i = *i + 1;
}

float           id_carac_tmp(int *i, t_list *tmp)
{
  float         cpt;

  cpt = 0.0;
  if (tmp->str[*i] <= 123 && tmp->str[*i] >= 97)
    cpt += tmp->str[*i] - 96;
  else if (tmp->str[*i] <= 90 && tmp->str[*i] >= 65)
    cpt += tmp->str[*i] - 64;
  else if (tmp->str[*i] >= '0' && tmp->str[*i] <= '9')
    cpt += tmp->str[*i] - 100;
  else if (tmp->str[*i] == '#')
    cpt += tmp->str[*i] - 200;
  else
    cpt += tmp->str[*i];
  return (cpt);
}

void    my_start(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2)
{
  int   i;
  float one;
  float two;

  i = 0;
  while (tmp != racine)
    {
      my_pass(&i , tmp, tmp2);
      my_correct_tmp(&i, tmp);
      my_correct_tmp(&i, tmp2);
      one = id_carac_tmp(&i, tmp);
      two = id_carac_tmp(&i, tmp2);
      if (two > one)
	tmp2 = tmp;
      tmp = tmp->next;
      i = 0;
    }
  find_small(racine, racine2, tmp, tmp2);
}
