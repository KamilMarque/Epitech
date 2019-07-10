/*
** listes.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 16:48:56 2016 kamil
** Last update Tue Jun 14 14:32:19 2016 kamil
*/

#include "my.h"

char		*my_strdup(char *str)
{
  char		*save;
  int		i;

  i = 0;
  if ((save = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
     return (NULL);
  while (str[i])
    save[i] = str[i++];
  save[i] = 0;
  return (save);
}

t_list          *my_create_list(t_list *racine)
{
  if ((racine = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  racine->prec = racine;
  racine->next = racine;
  return (racine);
}

char		**my_alloc_tab_after(int cpt, char *str, int i, int j)
{
  char		**tab;
  int		tmp;

  if ((tab = malloc(sizeof(char *) * cpt + 8)) == NULL)
    return (NULL);
  while (j < cpt)
    {
      tmp = 0;
      while (str[i++] != 39);
      while (str[i] != 39)
	{
	  i++;
	  tmp++;
	}
      if ((tab[j] = malloc(sizeof(char) * tmp + 1)) == NULL)
         return (NULL);
      i = i - tmp;
      tmp = 0;
      while (str[i] != 39)
	tab[j][tmp++] = str[i++];
      tab[j++][tmp] = 0;
      i = i + 2;
    }
  tab[j] = NULL;
  return (tab);
}

char		**my_alloc_tab_before(int cpt, char *str, int j, int i)
{
  char		**tab;
  int		tmp;

  if ((tab = malloc(sizeof(char *) * cpt + 8)) == NULL)
    return (NULL);
  while (j < cpt)
    {
      tmp = 0;
      while (str[++i] == ' ' || str[i] == '<');
      while (str[i++] != '=');
      while (str[i - 1] != ' ')
	{
	  i--;
	  tmp++;
	}
      if ((tab[j] = malloc(sizeof(char) * tmp + 1)) == NULL)
         return (NULL);
      tmp = 0;
      while (str[i] != '=')
      	tab[j][tmp++] = str[i++];
      tab[j++][tmp] = 0;
      i = i + 1;
    }
  tab[j] = NULL;
  return (tab);
}

void		*ajouteravant(t_list *racine, char *str, int cpt, char *save)
{
  t_list        *nouvel_element;

  if ((nouvel_element = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  nouvel_element->str = my_strdup(str);
  nouvel_element->tab_before = my_alloc_tab_before(cpt, save, 0, 0);
  nouvel_element->tab_after = my_alloc_tab_after(cpt, save, 0, 0);
  nouvel_element->prec = racine->prec;
  nouvel_element->next = racine;
  racine->prec->next = nouvel_element;
  racine->prec = nouvel_element;
}
