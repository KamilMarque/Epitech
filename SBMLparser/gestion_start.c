/*
** gestion_start.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Tue Jun 14 14:33:17 2016 kamil
** Last update Wed Jun 15 09:28:21 2016 kamil
*/

#include "my.h"

int		my_com_tri(char *str, char *str2)
{
  int		i;

  i = 0;
  while (str[i])
    {
      while (str[i] == str2[i])
	i++;
      if (str[i] < str2[i])
	return (1);
      else
	return (0);
    }
}

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void		trie_tab(char **tab, char **tab2, int i)
{
  int		j;
  int		k;
  char		*tmp2;

  while (i < my_tablen(tab) - 1)
    {
      j = 0;
      k = 0;
      while (j < my_tablen(tab) - 1)
	{
	  if (tab[j][k] > tab[j + 1][k])
	    {
	      my_tab_swap(tab, j);
	      my_tab_swap(tab2, j);
	      j++;
	    }
	  else if (tab[j][k] == tab[j + 1][k])
	    k++;
	  else
	    j++;
	}
      i++;
    }
}

void		my_swap(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  tmp->next->prec = list;
  list->prec->next = tmp;
  list->next = tmp->next;
  tmp->prec = list->prec;
  tmp->next = list;
  list->prec = tmp;
}

t_list		*my_tri_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list->next;
  while (tmp->next != list)
    {
      trie_tab(tmp->tab_before, tmp->tab_after, 0);
      if (tmp->str[0] > tmp->next->str[0])
	{
	  i++;
	  my_swap(tmp);
	}
      tmp = tmp->next;
    }
  if (i != 0)
    my_tri_list(list);
  return (list);
}
