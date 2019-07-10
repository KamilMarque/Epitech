/*
** main.c for mainc in /home/cathal_n/EPITECH_YEAR_2/unix_mem/malloc/PSU_2016_malloc
**
** Made by nicolas cathala
** Login   <cathal_n@epitech.net>
**
** Started on  Tue Jan 31 15:08:56 2017 nicolas cathala
** Last update Sun Feb 12 15:28:27 2017 nicolas cathala
*/

#include "malloc.h"

void	 *g_head = NULL;

size_t	align_size(size_t size)
{
  size_t result;

  result = size + 4;
  return (result);
}

void	*malloc(size_t size)
{
  t_block	*b;
  t_block	*last;
  size_t	s;

  s = align_size(size);
  if (g_head)
    {
      last = g_head;
      if ((b = my_create_list(last, s)) == NULL)
	return (NULL);
    }
  else
    {
      if ((b = my_create_list(NULL, s)) == NULL)
	return (NULL);
      g_head = b;
    }
  return (b->data);
}

void	*realloc(void *ptr, size_t size)
{
  void	*tmp;

  tmp = NULL;
  if (ptr)
    {
      if ((tmp = malloc(size)) == NULL)
	 return (NULL);
       memcpy(tmp, ptr, size);
       free(ptr);
    }
  else
    {
      if ((tmp = malloc(size)) == NULL)
	return (NULL);
    }
  return (tmp);
}
