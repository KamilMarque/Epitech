/*
** fill_tab2.c for  in /home/marque_p/rendu/osef/sudoku-bi
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sun Feb 28 19:36:25 2016 Kamil Marque
** Last update Sun Feb 28 19:48:27 2016 Kamil Marque
*/

#include "sudoku.h"

void		print_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    printf("%s\n", tab[i++]);
}

char            **false_map(char **map)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  while (map[i])
    {
      while (map[i][j])
	{
	  map[i][j] = 'X';
	  j++;
	}
      i++;
      j = 0;
    }
  return (map);
}

void            fill_map2(t_list *list, t_list *list2, char **tmp)
{
  tmp = nw_tab(tmp);
  list = my_att_pos(tmp);
  list2 = my_create_list(list2);
  list2 = my_tri_list(list, list2);
  tmp = solve_it(tmp, list2);
  print_my_tab(tmp);
}

char            **fill_map(t_list *list, t_list *list2)
{
  int           fd;
  char          *s;
  char          **tab_map;
  char          *save;
  int           i;
  char          **tmp;

  i = 0;
  s = malloc(sizeof(char *));
  save = NULL;
  while ((fd = read(0, s, 1)) > 0)
    save = my_save(s, save, fd);
  tab_map = my_str_to_wordtab(save, '\n');
  while (tab_map[i] != NULL)
    {
      tmp = new_tab(tab_map, &i);
      if ((check_map(tmp) != 1))
	exit (0);
      else
	{
	  if (i > 11)
	    printf("####################\n");
	  fill_map2(list, list2, tmp);
	}
    }
}
