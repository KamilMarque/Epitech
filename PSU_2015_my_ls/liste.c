/*
** liste.c for  in /home/marque_p/rendu/PSU_2015_my_ls
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Nov 25 18:37:07 2015 Kamil Marque
** Last update Fri Nov 27 16:44:40 2015 Kamil Marque
*/

#include "my.h"

t_list                  *my_create_list(t_list *racine)
{
  if ((racine = malloc(sizeof(struct s_list *))) == NULL)
    return (NULL);
  racine->next = racine;
  racine->prec = racine;
  return (racine);
}

void			*ajouterapres(t_list *element, char *array)
{
  t_list *nouvel_element;

  if ((nouvel_element = malloc(sizeof(nouvel_element))) == NULL)
    return (NULL);
  nouvel_element->str = array;
  nouvel_element->prec = element;
  nouvel_element->next = element->next;
  element->next->prec = nouvel_element;
  element->next = nouvel_element;
}

t_list                  *rotation_la(t_list *racine)
{
  t_list                *tmp;

  tmp = racine->next;
  racine->next = racine->next->next;
  racine->next->prec = racine;
  racine->prec->next = tmp;
  tmp->prec = racine->prec;
  racine->prec = tmp;
  tmp->next = racine;
}

int                     my_mouv_lb(t_list *racine, t_list *racine2)
{
  racine->next->prec = racine2;
  racine->next = racine->next->next;
  racine->next->prec->next = racine2->next;
  racine2->next = racine->next->prec;
  racine->next->prec = racine;
  racine2->next->next->prec = racine2->next;
}

void                    my_mouv_la(t_list *racine, t_list *racine2)
{
  racine2->next->prec = racine;
  racine2->next = racine2->next->next;
  racine2->next->prec->next = racine->next;
  racine->next = racine2->next->prec;
  racine2->next->prec = racine2;
  racine->next->next->prec = racine->next;
}
