/*
** requirement.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 09:26:43 2016 kamil
** Last update Mon Jun 13 09:58:58 2016 kamil
*/

#include <stdlib.h>
#include <unistd.h>

int		my_retern_int(char *str, int i)
{
  if (str[i] >= '0' && str[i] <= '9')
    return (1);
  else if (str[i] >= 'a' && str[i] <= 'z')
    return (1);
  else if (str[i] >= 'A' && str[i] <= 'Z')
    return (1);
  else if (str[i] == 0)
    return (2);
  else
    return (0);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (my_retern_int(str, i) == 1)
    i++;
  return (i);
}

int		count_word(char *str)
{
  int		i;
  int		cpt;

  cpt = 0;
  i = 0;
  while (str[i])
    {
      if (my_retern_int(str, i) == 0)
	{
	  while (my_retern_int(str, i) == 0)
	    i++;
	  if (str[i] != 0)
	    cpt++;
	}
      else
	i++;
    }
  return (cpt);
}

char		**my_strtowordtab_synthesis(char *str)
{
  int		nb_word;
  char		**tab;
  int		cpt;
  int		i;
  int		tmp;

  cpt = 0;
  i = 0;
  nb_word = count_word(str) + 1;
  if ((tab = malloc(sizeof(char *) * nb_word + 8)) == NULL)
     return (NULL);
  while (cpt < nb_word)
    {
      tmp = 0;
      while (my_retern_int(str, i) == 0)
	i++;
      if ((tab[cpt] = malloc(sizeof(char) * my_strlen(&str[i]) + 1)) == NULL)
         return (NULL);
      while (my_retern_int(str, i) == 1)
	tab[cpt][tmp++] = str[i++];
      tab[cpt][tmp] = 0;
      cpt++;
    }
  tab[cpt] = NULL;
  return (tab);
}
