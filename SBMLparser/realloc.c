/*
** realloc.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 13:31:26 2016 kamil
** Last update Wed Jun 15 10:37:03 2016 kamil
*/

#include "my.h"

char		*my_save(char *buf, char *save)
{
  int		cpt1;
  int		cpt2;
  char		*tmp;

  cpt1 = 0;
  cpt2 = 0;
  if (save != NULL)
    {
      if ((tmp = malloc(sizeof(char) * (my_strlen(buf)
					+ my_strlen(save) + 1))) == NULL)
	return (NULL);
      while (save[cpt1] != 0)
	tmp[cpt2++] = save[cpt1++];
      free(save);
    }
  else    if ((tmp = malloc(sizeof(char) * (my_strlen(buf) + 1))) == NULL)
    return (NULL);
  cpt1 = 0;
  while (buf[cpt1] != 0)
    tmp[cpt2++] = buf[cpt1++];
  tmp[cpt2] = 0;
  return (tmp);
}

int		my_compare(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] != s2[i])
	  return (0);
      i++;
    }
  if (s2[i] == 0)
    return (1);
  else
    return (0);
}

int             pars_start(char **av, t_list *list)
{
  int           i;

  i = 0;
  while (av[i])
    {
      if (my_compare(av[i], "-h") == 1)
	{
	  my_help();
	  return (1);
	}
      else if (my_compare(av[i], "-i") == 1)
	{
	  if (av[i + 1] == NULL)
	    {
	      my_putstr_error("Invalid -i\n");
	      return (1);
	    }
	  else
	    if (find_option_i(av[i + 1], list) == 1)
	      return (1);
	}
      i++;
    }
}

void            aff_spacies(t_list *list)
{
  int           i;
  t_list        *tmp;

  tmp = list->next;
  while (tmp != list)
    {
      i = 0;
      if (my_compare("species", tmp->str) == 1)
	{
	  while (tmp->tab_before[i])
	    {
	      if ((my_compare(tmp->tab_before[i], "name")) == 1 &&
		  tmp->tab_before[i] != NULL)
		{
		  my_putstr("----->");
		  my_putstr(tmp->tab_after[i]);
		  my_putstr("\n");
		}
	      i++;
	    }
	}
      tmp = tmp->next;
    }
}
