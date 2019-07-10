/*
** pars.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 10:22:56 2016 kamil
** Last update Wed Jun 15 15:33:12 2016 kamil
*/

#include "my.h"

static int	my_check_line(char *str)
{
  int		i;

  i = 1;
  while (str[i])
    {
      if (str[i] == '=')
	return (1);
      i++;
    }
  return (0);
}

static t_list	*my_start_pars(t_list *list, char **tab)
{
  int		i;

  i = 1;
  while (tab[i])
    {
      if (tab[i][1] == '?');
      else if (my_check_line(tab[i]) == 1)
	my_alloc_la(list, tab[i]);
      i++;
    }
}

static char	**read_and_alloc(char **av)
{
  int           fd;
  int           count;
  char          buf[200];
  char          *save;
  char		**tab;

  save = NULL;
  if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      my_putstr("Error happend while opening the file: '");
      my_putstr(av[1]);
      my_putstr("'\n");
      exit (84);
    }
  while ((count = read(fd, buf, 199)) != 0)
    {
      buf[count] = 0;
      save = my_save(buf, save);
    }
  if (save == NULL || save[0] != '<')
    exit (84);
  tab = str_to_wordtab(save, '\n');
  return (tab);
}

void		aff_list(t_list *list)
{
  t_list	*tmp;
  int		j;

  tmp = list->next;
  while (tmp != list)
    {
      if (tmp->prec == list || (my_compare(tmp->str, tmp->prec->str) == 0))
	{
	  j = 0;
	  my_putstr(tmp->str);
	  my_putstr("\n");
	  while (tmp->tab_before[j])
	    {
	      my_putstr("----->");
	      my_putstr(tmp->tab_before[j++]);
	      my_putstr("\n");
	    }
	}
      tmp = tmp->next;
    }
}

int             main(int ac, char **av)
{
  char		**tab;
  t_list	*list;

  if (ac == 1)
    return (84);
  list = my_create_list(list);
  tab = read_and_alloc(av);
  my_start_pars(list, tab);
  list = my_tri_list(list);
  if (ac == 2)
    aff_list(list);
  else if (pars_start(av, list) == 1)
    return (0);
}
