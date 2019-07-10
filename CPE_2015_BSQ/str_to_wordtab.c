/*
** str_to_wordtab.c for  in /home/marque_p/rendu/CPE_2015_BSQ
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Dec  2 11:32:01 2015 Kamil Marque
** Last update Sat Dec 19 12:33:19 2015 Kamil Marque
*/

#include "my.h"

int     wordline(char *source, char sep)
{
  int   i;

  i = 0;
  while (source[i] != sep)
    i++;
  return (i);
}

int     contword(char *source, char sep)
{
  int   i;
  int   c;

  i = 0;
  c = 0;
  while (source[i] != 0)
    {
      if (sep == source[i])
	c++;
      i++;
    }
  return (c);
}

char    **str_to_wordtab(char *source, char sep)
{
  int   nb_word;
  char  **tab;
  int   t;
  int   a;
  int   line;
  int	i;

  i = 0;
  a = -1;
  line = 0;
  nb_word = contword(source, sep);
  tab = malloc(sizeof(char *) * (nb_word + 1));
  while (++a < nb_word)
    {
      while (source[i] == sep && source[i] != 0)
	i++;
      line = wordline(&source[i], sep);
      tab[a] = malloc(sizeof(char) * (line + 1));
      my_strncpy(tab[a], &source[i], line);
      tab[a][line] = '\0';
      while (source[i] != sep)
	i++;
    }
  tab[nb_word] = 0;
  return (tab);
}
