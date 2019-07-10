/*
** liste.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Feb 16 09:36:08 2016 Kamil Marque
** Last update Wed Feb 24 06:55:01 2016 Kamil Marque
*/

#include "my.h"

t_list                  *my_create_list(t_list *racine)
{
  if ((racine = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  racine->prec = racine;
  racine->next = racine;
  return (racine);
}

void                    *ajouteravant(t_list *racine, char *str)
{
  t_list                *nouvel_element;

  if ((nouvel_element = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  nouvel_element->select = 0;
  nouvel_element->str = my_strdup(str);
  nouvel_element->prec = racine->prec;
  nouvel_element->next = racine;
  racine->prec->next = nouvel_element;
  racine->prec = nouvel_element;

}
