/*
** str_to_wordtab.c for  in /home/henry_g/rendu/projTester
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Fri Jun 19 19:02:30 2015 Clément Henry
** Last update Sun Feb 28 15:30:19 2016 Kamil Marque
*/

#include "sudoku.h"

int	how_alloc(char *str, char what, int index)
{
  int	ct;

  ct = 0;
  while (str[index] != '\0' && str[index] != what)
    {
      index++;
      ct++;
    }
  return (ct);
}

void    print_my_tab(char **tab)
{
  int   i;
  int	j;

  j = 0;
  i = 0;
  printf("|------------------|\n");
  while (tab[i])
    {
      printf("|");
      while (tab[i][j])
	{
	  printf(" ");
	  printf("%c", tab[i][j]);
	  j++;
	}
      printf("|");
      printf("\n");
      i++;
      j = 0;
    }
  printf("|------------------|\n");
}

int     count_words(char *str, char what)
{
  int   i;
  int   counter;

  i = 0;
  counter = 0;
  while (str[i] != '\0')
    {
      if (str[i] == what)
	counter++;
      i++;
    }
  return (counter);
}

void	initialise(int *i, int *j)
{
  *i = -1;
  *j = 0;
}

char	**my_str_to_wordtab(char *str, char what)
{
  int	column;
  int	line;
  char	**tab;
  int	i;

  initialise(&i, &line);
  if ((tab = malloc((count_words(str, what) + 2) * sizeof(char *))) == NULL)
    return (NULL);
  while (++i < strlen(str))
    {
      column = 0;
      if ((tab[line] = malloc
	   ((how_alloc(str, what, i) + 2) * sizeof(char))) == NULL)
	return (NULL);
      while (str[i] && str[i] != what)
	tab[line][column++] = str[i++];
      tab[line][column] = '\0';
      line++;
    }
  tab[line] = NULL;
  return (tab);
}
