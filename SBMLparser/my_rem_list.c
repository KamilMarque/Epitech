/*
** my_rem_list.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 17:46:08 2016 kamil
** Last update Tue Jun 14 14:30:46 2016 kamil
*/

#include "my.h"

static char	*name_maill(char *str)
{
  int		i;
  int		j;
  char		*save;

  j = 0;
  i = 1;
  while (str[i] != ' ')
    i++;
  if ((save = malloc(sizeof(char) * i)) == NULL)
     return (NULL);
  while (j < i - 1)
    {
      save[j] = str[j + 1];
      j++;
    }
  save[j] = 0;
  return (save);
}

static int	count_arg(char *str)
{
  int		i;
  int		cpt;

  cpt = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '=')
	cpt++;
      i++;
    }
  return (cpt);
}

char		*my_alloc_la(t_list *list, char *str)
{
  char		*save;
  int		i;
  int		cpt;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  save = name_maill(&str[i]);
  cpt = count_arg(&str[i]);
  ajouteravant(list, save, cpt, &str[i]);
}
