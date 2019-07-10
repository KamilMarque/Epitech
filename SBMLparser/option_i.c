/*
** option_i.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Wed Jun 15 10:06:50 2016 kamil
** Last update Wed Jun 15 11:13:36 2016 kamil
*/

#include "my.h"

void		aff_cyto(t_list *tmp)
{
  int		i;

  i = 0;
  while (tmp->tab_before[i] != NULL &&
	 my_compare(tmp->tab_before[i], "name") == 0)
    i++;
  if (tmp->tab_before[i] == NULL)
    return ;
  my_putstr(tmp->tab_after[i]);
  my_putstr("\n");
}

int		find_option_i2(char *str, t_list *list)
{
  t_list	*tmp;
  int		i;

  tmp = list->next;
  if (my_compare(str, "compartment") == 1)
    {
      i = 0;
      my_putstr("List of species in compartment ");
      while (tmp->tab_before[i] != NULL &&
	     (my_compare(tmp->str, "species") == 1) &&
	     (my_compare(tmp->tab_before[i], "name") == 0))
	i++;
      my_putstr(tmp->tab_after[i]);
      my_putstr("\n");
      while (tmp != list)
	{
	  if (my_compare(tmp->str, "species") == 1)
	    {
	      my_putstr("----->");
	      aff_cyto(tmp);
	    }
	  tmp = tmp->next;
	}
      return (1);
    }
}

int		find_option_i(char *str, t_list *list)
{
  int		i;
  t_list	*tmp;

  i = 0;
  tmp = list->next;
  while (tmp != list)
    {
      i = 0;
      while (tmp->tab_after[i])
	{
	  if (my_compare(str, tmp->tab_after[i]) == 1)
	    if (find_option_i2(tmp->str, list) == 1)
	      return (1);
	  i++;
	}
      tmp = tmp->next;
    }
  my_putstr("List of species\n");
  aff_spacies(list);
}
