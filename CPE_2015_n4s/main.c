/*
** main.c for  in /home/marque_p/rendu/CPE_2015_n4s/kamel/test2
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Sat May 28 14:50:41 2016 kamil
** Last update Sun May 29 21:00:40 2016 Clément
*/

#include "get_next_line.h"

int             my_cmp(char *s1, char *s2)
{
  int           i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] == s2[i])
	i++;
      else
	return (0);
    }
  return (1);
}

int             my_return(char *str)
{
  write(2, str, my_strlen(str));
  return (1);
}

int		main()
{
  char		*rep;
  char		**tab;

  my_putstr("START_SIMULATION\n");
  rep = get_next_line(0);
  if ((my_cmp("1:OK:No errors so far:No further info", rep)) == 0)
    return (my_return("START_SIMULATION Fail !"));
  my_putstr("CAR_FORWARD:0.1\n");
  rep = get_next_line(0);
  if ((my_cmp("1:OK:No errors so far:No further info", rep)) == 0)
    return (my_return("CAR_FORWARD Fail !"));
  while (42)
    {
      my_putstr("GET_INFO_LIDAR\n");
      rep = get_next_line(0);
      tab = str_to_wordtab(rep, ':');
      if (tab[35][0] == 'T' && tab[35][0] == 'R')
	{
	  my_putstr("STOP_SIMULATION\n");
	  return (0);
	}
      algo(tab);
      rep = get_next_line(0);
    }
}
