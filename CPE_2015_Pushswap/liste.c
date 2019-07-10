/*
** liste.c for  in /home/marque_p/rendu/CPE_2015_Pushswap
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Nov 22 18:11:05 2015 Kamil Marque
** Last update Sun Nov 22 19:15:13 2015 Kamil Marque
*/

#include "my.h"

t_list                  *my_create_list(t_list *racine)
{
  if ((racine = malloc(sizeof(struct s_list *))) == NULL)
    return (NULL);
  racine->prec = racine;
  racine->next = racine;
  return (racine);
}

void                    *ajouteravant(t_list *racine, int val)
{
  t_list                *nouvel_element;

  if ((nouvel_element = malloc(sizeof(nouvel_element))) == NULL)
    return (NULL);
  nouvel_element->val = val;
  nouvel_element->next = racine;
  racine->prec->next = nouvel_element;
  nouvel_element->prec = racine->prec;
  racine->prec = nouvel_element;
}

int                     my_mouv_lb(t_list *racine, t_list *racine2)
{
  racine->next->prec = racine2;
  racine->next = racine->next->next;
  racine->next->prec->next = racine2->next;
  racine2->next = racine->next->prec;
  racine->next->prec = racine;
  racine2->next->next->prec = racine2->next;
  write(1, "pb ", 3);
}

void                    my_mouv_la(t_list *racine, t_list *racine2)
{
  racine2->next->prec = racine;
  racine2->next = racine2->next->next;
  racine2->next->prec->next = racine->next;
  racine->next = racine2->next->prec;
  racine2->next->prec = racine2;
  racine->next->next->prec = racine->next;
  write(1, "pa ", 3);
}

void                    my_mouv_la_sp(t_list *racine, t_list *racine2)
{
  racine2->next->prec = racine;
  racine2->next = racine2->next->next;
  racine2->next->prec->next = racine->next;
  racine->next = racine2->next->prec;
  racine2->next->prec = racine2;
  racine->next->next->prec = racine->next;
  write(1, "pa", 2);
}
