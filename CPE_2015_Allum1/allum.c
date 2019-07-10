/*
** allum.c for  in /home/marque_p/rendu/CPE_2015_Allum1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Feb 16 14:12:57 2016 Kamil Marque
** Last update Sun Feb 21 01:28:58 2016 Kamil Marque
*/

#include "my.h"

int		my_ia_moov(t_allum *allum)
{
  if (my_final_check(allum) == 1)
    {
      my_final_mouv(allum);
      return (1);
    }
  else if (my_final_check(allum) == 2)
    {
      my_spec_mouv(allum);
      return (1);
    }
}

void		my_ai(t_allum *allum)
{
  int		i;
  int		tmp;
  int		rec_xor;

  i = 0;
  while (i != 4)
    {
      tmp = 1;
      while (tmp <= allum->tab[i])
	{
	  if (my_ia_moov(allum) == 1)
	    return ;
	  allum->tab[i] = allum->tab[i] - tmp;
	  if ((rec_xor = my_xor(allum)) == 0)
	    {
	      my_put_nbr(tmp);
	      my_putstr(" match(es) from line ");
	      my_put_nbr(i + 1);
	      return ;
	    }
	  allum->tab[i] = allum->tab[i] + tmp;
	  tmp++;
	}
      i++;
    }
}

int		my_comm(t_allum *allum)
{
  char		*str;
  char		*str2;

  while (42)
    {
      if ((str = my_check_line(allum)) == NULL)
	return (2);
      if ((my_check_matches(str, allum)) == NULL)
	return (2);
      my_putstr(" match(es) from line ");
      my_putstr(str);
      my_putchar('\n');
      my_allum(allum);
      if (my_check_win(allum) == 1)
	return (2);
      my_putchar('\n');
      my_putstr("AI's turn...\n");
      my_putstr("AI removed ");
      my_ai(allum);
      my_putstr("\n");
      my_aff(allum);
      my_putstr("\n");
      my_putstr("Your turn:\n");
    }
}

int		main(int ac, char **av)
{
  t_allum	allum;
  int		check;

  allum.tab = my_create_tab(allum.tab);
  my_allum(&allum);
  my_putchar('\n');
  my_putstr("Your turn:\n");
  if ((check = my_comm(&allum)) == 2)
    return (0);
}
