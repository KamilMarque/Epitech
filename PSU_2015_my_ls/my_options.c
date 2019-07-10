/*
** my_options.c for  in /home/marque_p/rendu/PSU_2015_my_ls
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Fri Nov 27 16:13:03 2015 Kamil Marque
** Last update Sun Nov 29 21:06:00 2015 Kamil Marque
*/

#include "my.h"

void			my_r(t_list *racine, t_check *check)
{
  t_list		*tmp;
  DIR			*dir;
  struct	dirent	*dire;
  t_list		*racine2;
  t_list		*racine3;

  racine2 = my_create_list(racine2);
  racine3 = my_create_list(racine3);
  tmp = racine->next;
  if (tmp == racine)
    dir = opendir(".");
  else
    dir = opendir(tmp->str);
  while ((dire = readdir(dir)) != NULL)
    {
      if (dire->d_name[0] == '.');
      else
	ajouterapres(racine2, dire->d_name);
    }
  my_trie(racine2, racine3);
  tmp = racine2->prec;
  my_aff(racine2);
}

void                    my_basic_ls(t_list *racine2, t_list *racine3)
{
  DIR                   *dir;
  struct dirent         *dire;
  t_list                *tmp;
  int                   i;

  dir = opendir(".");
  while ((dire = readdir(dir)) != NULL)
    {
      if (dire->d_name[0] == '.');
      else
	ajouterapres(racine2, dire->d_name);
    }
  my_trie(racine2, racine3);
  tmp = racine2->next;
  while (tmp != racine2)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int			my_check_correct_option(char c)
{
  if ((c <= 'z' && c >= 'a') || c <= 'Z' && c >= 'A')
    return ;
  else
    {
      my_putstr_error("ls: invalid option -- '");
      write(2, &c, 1);
      write(2, "'", 1);
      my_putchar('\n');
    }
}

int			my_options(char *array, t_check *check)
{
  int			i;

  i = 1;
  while (array[i] != 0)
    {
      if (array[i] == 'l')
	check->l = 1;
      else if (array[i] == 'r')
	check->r = 1;
      else if (array[i] == 'd')
	check->d = 1;
      else if (array[i] == 't')
	check->t = 1;
      else if (array[i] == 'R')
	check->big_r = 1;
      else
	my_check_correct_option(array[i]);
      i++;
    }
}

void			my_d(t_list *racine, t_check *check)
{
  t_list		*tmp;

  tmp = racine->next;
  if (tmp == racine)
    my_putstr(".\n");
  else
    while (tmp != racine)
      {
	my_putstr(tmp->str);
	my_putchar('\n');
	tmp = tmp->next;
      }
}
