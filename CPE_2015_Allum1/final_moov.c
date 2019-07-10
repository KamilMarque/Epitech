/*
** final_moov.c for  in /home/marque_p/rendu/CPE_2015_Allum1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Feb 21 01:04:00 2016 Kamil Marque
** Last update Sun Feb 21 01:29:42 2016 Kamil Marque
*/

#include "my.h"

int     my_final_check(t_allum *allum)
{
  int   i;
  int   k;
  int   one;

  one = 0;
  k = 0;
  i = 0;
  while (i != 4)
    {
      if (allum->tab[i] > 1)
	k++;
      if (allum->tab[i] == 1)
	one++;
      i++;
    }
  if (k == 1)
    return (1);
  else if (one == 4 || (one == 2 && k != 2))
    return (2);
  else
    return (0);
}

void    my_final_mouv2(t_allum *allum, int i, int nb_matches)
{
  if (nb_matches == allum->tab[i] + 3)
    {
      my_put_nbr(allum->tab[i]);
      allum->tab[i] = allum->tab[i]  - allum->tab[i];
      my_putstr(" match(es) from line ");
      my_put_nbr(i + 1);
    }
  else if (nb_matches == allum->tab[i] + 2)
    {
      my_put_nbr(allum->tab[i] - 1);
      allum->tab[i] = allum->tab[i]  - (allum->tab[i] - 1);
      my_putstr(" match(es) from line ");
      my_put_nbr(i + 1);
    }
}

void    my_final_mouv(t_allum *allum)
{
  int   i;
  int   nb_matches;

  i = 0;
  nb_matches = allum->tab[0] + allum->tab[1] + allum->tab[2] + allum->tab[3];
  while (allum->tab[i] < 2)
    i++;
  if (nb_matches == allum->tab[i])
    {
      allum->tab[i] = allum->tab[i] - (nb_matches - 1);
      my_put_nbr(nb_matches - 1);
      my_putstr(" match(es) from line ");
      my_put_nbr(i + 1);
    }
  else if (nb_matches == allum->tab[i] + 1)
    {
      allum->tab[i] = allum->tab[i] - (nb_matches - 1);
      my_put_nbr(nb_matches - 1);
      my_putstr(" match(es) from line ");
      my_put_nbr(i + 1);
    }
  else
    my_final_mouv2(allum, i, nb_matches);
}

void    my_spec_mouv(t_allum *allum)
{
  int   i;
  int   j;
  int   nb_matches;

  j = 0;
  i = 1;
  nb_matches = allum->tab[0] + allum->tab[1] + allum->tab[2] + allum->tab[3];
  while (i != allum->tab[j])
    j++;
  if (i == allum->tab[j])
    {
      allum->tab[j] = allum->tab[j] - 1;
      my_put_nbr(1);
      my_putstr(" match(es) from line ");
      my_put_nbr(j + 1);
    }
}
