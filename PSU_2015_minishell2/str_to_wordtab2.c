/*
** str_to_wordtab2.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Fri Mar 18 17:17:36 2016 Kamil Marque
** Last update Tue Mar 29 14:59:25 2016 kamil
*/

#include "my.h"

int	contword(char *str, char sep)
{
  int	i;
  int	x;

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

int	my_strlen_tab(char *str, char sep)
{
  int	i;

  i = 0;
  while (str[i] != sep && str[i] != 0)
    {
      if (str[i] == 0)
	exit(0);
      i++;
    }
  return (i + 1);
}

char	**str_to_wordtab(char *str, char sep)
{
  int	x;
  int	y;
  int	j;
  char	**tab;

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
