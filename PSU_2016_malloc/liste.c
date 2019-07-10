/*
** liste.c for  in /home/marque_p/rendu/PSU_2016_malloc
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Jan 31 14:21:31 2017 Kamil Marque
** Last update Thu Feb  9 16:43:59 2017 nicolas cathala
*/

#include "malloc.h"

t_block			*my_create_list(t_block *end, size_t size)
{
  t_block		*tmp;

  tmp = sbrk(0);
  if ((sbrk(SIZE_BLOCK + size)) == (void*)-1)
    return (NULL);
  tmp->size = size;
  tmp->next = NULL;
  tmp->begin = MAGIC;
  if (end != NULL)
    {
      end->next = tmp;
      tmp->prev = end;
    }
  tmp->_free = 0;
  return (tmp);
}
