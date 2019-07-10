/*
** fill_tab.c for  in /home/henry_g/sudoku-bi
** 
** Made by Clément Henry
** Login   <henry_g@epitech.net>
** 
** Started on  Sat Feb 27 18:12:43 2016 Clément Henry
** Last update Sun Feb 28 19:47:49 2016 Kamil Marque
*/

#include "sudoku.h"

char		**nw_tab(char **tab_map)
{
  char		**nw_map;
  int		i;
  int		j;
  int		counter;

  i = -1;
  tab_map++;
  if ((nw_map = malloc(sizeof(char *) * 10)) == NULL)
    return (NULL);
  while (++i != 9)
    {
      counter = 0;
      j = 2;
      if ((nw_map[i] = malloc(sizeof(char) *
			      (strlen(tab_map[i]) - 2))) == NULL)
	return (NULL);
      while (j != 20)
	{
	  nw_map[i][counter++] = tab_map[i][j];
	  j = j + 2;
	}
      nw_map[i][counter] = '\0';
    }
  nw_map[i] = NULL;
  return (nw_map);
}

char            *my_save(char *buf, char *save, int count)
{
  int           cpt1;
  int           cpt2;
  char          *tmp;

  cpt1 = 0;
  cpt2 = 0;
  buf[count] = 0;
  if (save != NULL)
    {
      if ((tmp = malloc(sizeof(char) * (strlen(buf)
					+ strlen(save) + 1))) == NULL)
	return (NULL);
      while (save[cpt1] != 0)
	tmp[cpt2++] = save[cpt1++];
    }
  else
    if ((tmp = malloc(sizeof(char) * (strlen(buf) + 1))) == NULL)
      return (NULL);
  cpt1 = 0;
  while (buf[cpt1] != 0)
    tmp[cpt2++] = buf[cpt1++];
  tmp[cpt2] = 0;
  return (tmp);
}

char		**new_tab(char **map, int *i)
{
  char		**ta_map;
  int		counter;
  int		tmp;

  tmp =  (*i + 11);
  counter = 0;
  ta_map = malloc(sizeof(char *) * 12);
  while (*i != tmp)
    {
      ta_map[counter] = strdup(map[*i]);
      counter++;
      (*i)++;
    }
  ta_map[counter] = NULL;
  return (ta_map);
}
