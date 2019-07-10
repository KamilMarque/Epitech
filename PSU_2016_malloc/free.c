/*
** free.c for  in /home/marque_p/rendu/PSU_2016_malloc
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Jan 31 14:50:29 2017 Kamil Marque
** Last update Sun Feb 12 15:22:47 2017 nicolas cathala
*/

#include "malloc.h"

void		free(void *block)
{
  t_block	*tmp;

  tmp = NULL;
  if (!block)
    return ;
  tmp = block;
  if (tmp && tmp->begin == MAGIC)
    tmp->_free = 1;
  return ;
}
