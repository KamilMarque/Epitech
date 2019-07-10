/*
** trie.c for  in /home/marque_p/rendu/CPE_2015_Pushswap
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Nov 22 18:14:43 2015 Kamil Marque
** Last update Sun Nov 22 19:16:47 2015 Kamil Marque
*/

#include "my.h"

int	find_small(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2)
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

int	my_final(t_list *racine, t_list *racine2, int ac)
{
  int   i;

  i = 1;
  if (racine->next == racine)
    {
      while (i != ac - 1)
	{
	  my_mouv_la(racine , racine2);
	  i++;
	}
      return (1);
    }
}

void	my_start(t_list *racine, t_list *racine2, t_list *tmp, t_list *tmp2)
{
  while (tmp != racine)
    {
      if (tmp2->val > tmp->val)
	tmp2 = tmp;
      tmp = tmp->next;
    }
  find_small(racine, racine2, tmp, tmp2);
}
