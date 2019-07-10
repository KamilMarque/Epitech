/*
** my_tab.c for  in /home/marque_p/rendu/CPE_2015_Allum1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Feb 21 00:58:54 2016 Kamil Marque
** Last update Sun Feb 21 01:33:22 2016 Kamil Marque
*/

#include "my.h"

int             *my_create_tab(int *tab)
{
  int		i;

  i = 0;
  if ((tab = malloc(sizeof(int) * 4)) == NULL)
    return (NULL);
  while (i != 4)
    {
      tab[i] = i * 2 + 1;
      i++;
    }
  return (tab);
}

int		my_aff2(t_allum *allum, int *k, int *i, int j)
{
  my_putchar('*');
  while (*k != (8 / 2 - (*i + 1)))
    {
      my_putchar(' ');
      *k = *k + 1;
    }
  while (j != allum->tab[*i])
    {
      my_putchar('|');
      j++;
    }
  return (j);
}

void            my_aff(t_allum *allum)
{
  int           i;
  int           j;
  int           k;

  i = 0;
  my_putstr("*********\n");
  while (i != 4)
    {
      j = 0;
      k = 0;
      j = my_aff2(allum, &k, &i, j);
      while (j != 7 - k)
	{
	  my_putchar(' ');
	  j++;
	}
      my_putchar('*');
      my_putchar('\n');
      i++;
    }
  my_putstr("*********\n");
}

void            my_allum(t_allum *allum)
{
  my_aff(allum);
}
