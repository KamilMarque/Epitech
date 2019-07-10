/*
** my_algo2.c for  in /home/marque_p/rendu/ia/CPE_2015_n4s
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Sun May 29 22:45:28 2016 kamil
** Last update Sun May 29 22:46:25 2016 kamil
*/

#include "get_next_line.h"

int     return_min_val(char **tab)
{
  int   i;
  int   res;

  i = 3;
  res = my_getnbr(tab[i]);
  while (tab[i])
    {
      if (my_getnbr(tab[i]) < res)
	res = my_getnbr(tab[i]);
      i++;
    }
  return (res);
}

int     verf_courb2(char **tab)
{
  int   i;
  int   res;

  i = 3;
  res = i;
  while (tab[i + 1])
    {
      if (my_getnbr(tab[i]) <= res && my_getnbr(tab[i]) < 800)
	{
	  res = my_getnbr(tab[i]);
	  i++;
	}
      else        return (0);
    }
  return (1);
}
int     verf_courb(char **tab)
{
  int   i;
  int   res;

  i = 3;
  res = i;
  while (tab[i + 1])
    {
      if (my_getnbr(tab[i]) >= res && my_getnbr(tab[i]) < 800)
	{
	  res = my_getnbr(tab[i]);
	  i++;
	}
      else        return (0);
    }
  return (1);
}

void    go_left(int left, int right, int res)
{
  if (res >= -1000)
    my_putstr("WHEELS_DIR:-0.40\n");
  else if (res >= -2000)
    my_putstr("WHEELS_DIR:-0.20\n");
  else if (res >= -3000)
    my_putstr("WHEELS_DIR:-0.25\n");
  else if (res >= -5000)
    my_putstr("WHEELS_DIR:-0.30\n");
  else if (res >= -7000)
    my_putstr("WHEELS_DIR:-0.35\n");
  else if (res >= -8000)
    my_putstr("WHEELS_DIR:-0.40\n");
  else if (res >= -9000)
    my_putstr("WHEELS_DIR:-0.45\n");
  else if (res >= -10000)
    my_putstr("WHEELS_DIR:-0.50\n");
  else if (res >= -12000)
    my_putstr("WHEELS_DIR:-0.55\n");
  else if (res >= -15000)
    my_putstr("WHEELS_DIR:-0.80\n");
  else if (res >= -17000)
    my_putstr("WHEELS_DIR:-0.85\n");
  else    my_putstr("WHEELS_DIR:-0.8\n");
}
