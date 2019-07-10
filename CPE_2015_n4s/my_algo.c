/*
** my_algo.c for  in /home/marque_p/rendu/ia/CPE_2015_n4s
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Sun May 29 22:50:02 2016 kamil
** Last update Sun May 29 22:50:03 2016 kamil
*/

#include "get_next_line.h"

void	go_right(int left, int right, int res)
{
  if (res <= 1000)
    my_putstr("WHEELS_DIR:0.40\n");
  else if (res <= 2000)
    my_putstr("WHEELS_DIR:0.20\n");
  else if (res <= 3000)
    my_putstr("WHEELS_DIR:0.25\n");
  else if (res <= 5000)
    my_putstr("WHEELS_DIR:0.30\n");
  else if (res <= 7000)
    my_putstr("WHEELS_DIR:0.35\n");
  else if (res <= 8000)
    my_putstr("WHEELS_DIR:0.40\n");
  else if (res <= 9000)
    my_putstr("WHEELS_DIR:0.45\n");
  else if (res <= 10000)
    my_putstr("WHEELS_DIR:0.50\n");
  else if (res <= 12000)
    my_putstr("WHEELS_DIR:0.55\n");
  else if (res <= 15000)
    my_putstr("WHEELS_DIR:0.8\n");
  else if (res <= 17000)
    my_putstr("WHEELS_DIR:0.85\n");
  else
    my_putstr("WHEELS_DIR:0.8\n");
}

int	start_tab(char **tab)
{
  int	i;
  int	res;

  res = 0;
  i = 0;
  while (i != 4)
    {
      res = res + my_getnbr(tab[i + 3]);
      i++;
    }
  return (res);
}

int	end_tab(char **tab)
{
  int	i;
  int	res;

  res = 0;
  i = 19;
  while (i != 23)
    {
      res = res + my_getnbr(tab[i]);
      i++;
    }
  return (res);
}

int	init(int *left, int *right, int *res, char **tab)
{
  my_putstr("CAR_FORWARD:0.2\n");
  get_next_line(0);
  *left = start_tab(tab);
  *right = end_tab(tab);
  *res = *left - *right;
   if ((tab[4][0] > '9' && tab[4][0] < '0') || my_getnbr(tab[16]) > 600)
    {
      my_putstr("WHEELS_DIR:0.0\n");
      return (0);
    }
   return (1);
}

int	algo(char **tab)
{
  int	left;
  int	right;
  int	res;

  if (init(&left, &right, &res, tab) == 0)
    return (0);
  if (verf_courb2(tab) == 1)
    if (my_getnbr(tab[16]) <= 500)
      res = res * 10;
    else if (my_getnbr(tab[16]) <= 400)
      res = res * 100;
    else
      res = res * 5;
  else if (verf_courb(tab) == 1)
    if (my_getnbr(tab[16]) <= 500)
      res = res * 10;
    else if (my_getnbr(tab[16]) <= 400)
      res = res * 100;
    else
      res = res * 5;
  if (res >= 0)
    go_right(left, right, res);
  else if (res < 0)
    go_left(left, right, res);
}
