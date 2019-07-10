/*
** str_to_wordtab.c for  in /home/marque_p/rendu/CPE_2015_n4s/kamel
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Thu May 26 19:52:29 2016 kamil
** Last update Sat May 28 15:02:21 2016 kamil
*/

#include "get_next_line.h"

int     contword(char *str, char sep)
{
  int   i;
  int   x;

  i = 0;
  x = 0;
  while (str[i] != 0)
    {
      if (str[i] == sep)
	x++;
      i++;
    }
  return (x + 1);
}

int     my_strlen_tab(char *str, char sep)
{
  int   i;

  i = 0;
  while (str[i] != sep && str[i] != 0)
    {
      if (str[i] == 0)
	exit(0);
      i++;
    }
  return (i + 1);
}

char    **str_to_wordtab(char *str, char sep)
{
  int   x;
  int   y;
  int   j;
  char  **tab;

  x = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * (contword(str, sep)))) == NULL)
    return (NULL);
  while (str[x])
    {
      y = 0;
      if ((tab[j] = malloc(sizeof(char) *
			   (my_strlen_tab(&str[x], sep) + 1))) == NULL)
	return (NULL);
      while (str[x] != sep && str[x] != 0)
	tab[j][y++] = str[x++];
      tab[j][y] = 0;
      if (str[x] != 0)
	x++;
      j++;
    }
  tab[j] = NULL;
  return (tab);
}
