/*
** my_check.c for  in /home/marque_p/rendu/CPE_2015_Allum1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Feb 21 01:01:59 2016 Kamil Marque
** Last update Thu Feb 25 14:03:38 2016 Kamil Marque
*/

#include "my.h"

int     my_check_arg(char *line)
{
  int   i;

  i = 0;
  if (line[0] == 0)
    return (1);
  while (line[i])
    {
      if (line[i] <= '9' && line[i] >= '0')
	i++;
      else
	return (1);
    }
  return (0);
}

char    *my_check_line(t_allum *allum)
{
  my_putstr("Line: ");
  if ((allum->str = get_next_line(0)) == NULL)
    return (NULL);
  allum->line_c = my_getnbr(allum->str);
  if (allum->line_c < 0 || my_check_arg(allum->str) == 1)
    {
      my_putstr("Error: invalid input (positive number expected)\n");
      my_check_line(allum);
    }
  else if (allum->line_c == 1 || allum->line_c == 2 ||
	   allum->line_c == 3 || allum->line_c == 4)
    {
      if (allum->tab[allum->line_c - 1] == 0)
	{
	  my_putstr("Error: this line is empty\n");
	  my_check_line(allum);
	}
      else
        return (allum->str);
    }
  else
    {
      my_putstr("Error: this line is out of range\n");
      my_check_line(allum);
    }
}

char    *my_check_matches(char *line, t_allum *allum)
{
  my_putstr("Matches: ");
  if ((allum->matches_c = get_next_line(0)) == NULL)
    return (NULL);
  allum->tmp_c = my_getnbr(allum->matches_c);
  allum->line_c = my_getnbr(line) - 1;
  if (allum->tmp_c > allum->tab[allum->line_c])
    {
      my_putstr("Error: not enough matches on this line\n");
      if (my_comm(allum) == 2)
	return (NULL);
    }
  else if (my_check_arg(allum->matches_c) == 1 || allum->tmp_c == 0)
    {
      if (my_check_arg(allum->matches_c) == 1)
	my_putstr("Error: invalid input (positive number expected)\n");
      else if (allum->tmp_c == 0)
	my_putstr("Error: you have to remove at least one match\n");
      if (my_comm(allum) == 2)
	return (NULL);
    }
  else
    allum->tab[allum->line_c] = allum->tab[allum->line_c] - allum->tmp_c;
  my_putstr("Player removed ");
  my_put_nbr(allum->tmp_c);
  return (allum->matches_c);
}

int     my_check_win(t_allum *allum)
{
  int   i;

  i = 0;
  while (i != 4)
    {
      if (allum->tab[i] == 0)
	i++;
      else
	return (0);
    }
  my_putstr("You lost, too bad..\n");
  return (1);
}

int     my_xor(t_allum *allum)
{
  int   i;
  int   res;

  i = 0;
  res = 0;
  while (i != 4)
    res = res ^ allum->tab[i++];
  return (res);
}
