/*
** malloc.h for malloc in /home/cathal_n/EPITECH_YEAR_2/unix_mem/malloc/PSU_2016_malloc
**
** Made by nicolas cathala
** Login   <cathal_n@epitech.net>
**
** Started on  Tue Jan 31 15:18:53 2017 nicolas cathala
** Last update Sun Feb 12 15:24:59 2017 nicolas cathala
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define		SIZE_BLOCK (sizeof(struct s_block))
# define		MAGIC 3500

extern void		*head;

typedef struct		s_block
{
  int			begin;
  size_t		size;
  struct s_block	*next;
  struct s_block	*prev;
  int			_free;
  char			data[1];
}			t_block;

void			*malloc(size_t);
void			*realloc(void *, size_t);
t_block			*my_create_list(t_block *, size_t);
void			free(void *);

#endif /* !MALLOC_H_ */
