/*
** my_fonction.c for  in /home/marque_p/rendu/PSU_2015_my_ls
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Fri Nov 27 15:24:19 2015 Kamil Marque
** Last update Sun Nov 29 17:43:41 2015 Kamil Marque
*/

#include "my.h"

int     my_save(int ac, char **av, t_list *racine, t_check *check)
{
  int   i;

  i = 1;
  while (i != ac)
    {
      if (av[i][0] == '-')
	my_options(av[i], check);
      else
	{
	  if (open(av[i], O_RDONLY) != -1 || opendir(av[i]) != NULL)
	    ajouterapres(racine, av[i]);
	}
      i++;
    }
}

void    ini_check(t_check *check)
{
  check->l = 0;
  check->r = 0;
  check->t = 0;
  check->d = 0;
  check->big_r = 0;
}

void	my_ls_dir2(t_list *racine, t_list *racine3, t_list *tmp,  int *i)
{
  tmp = racine3->next;
  while (tmp != racine3)
    {
      my_putstr(tmp->str);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

int     my_ls_dir(t_list *racine, t_list *racine2)
{
  DIR                   *dir;
  struct dirent         *dire;
  t_list                *tmp;
  t_list              *racine3;
  int                   i;

  i = 0;
  tmp = racine;
  dir = opendir(tmp->str);
  racine3 = my_create_list(racine3);
  while ((dire = readdir(dir)) != NULL)
    {
      if (dire->d_name[0] == '.');
      else
	ajouterapres(racine3, dire->d_name);
    }
  my_trie(racine3, racine2);
  my_ls_dir2(racine, racine3, tmp, &i);
}

int     right(mode_t st_mode)
{
  ((st_mode & S_IFDIR) != 0) ? my_putstr("d") : my_putstr("-");
  ((st_mode & S_IRUSR) != 0) ? my_putstr("r") : my_putstr("-");
  ((st_mode & S_IWUSR) != 0) ? my_putstr("w") : my_putstr("-");
  ((st_mode & S_IXUSR) != 0) ? my_putstr("x") : my_putstr("-");
  ((st_mode & S_IRGRP) != 0) ? my_putstr("r") : my_putstr("-");
  ((st_mode & S_IWGRP) != 0) ? my_putstr("w") : my_putstr("-");
  ((st_mode & S_IXGRP) != 0) ? my_putstr("x") : my_putstr("-");
  ((st_mode & S_IROTH) != 0) ? my_putstr("r") : my_putstr("-");
  ((st_mode & S_IWOTH) != 0) ? my_putstr("w") : my_putstr("-");
  ((st_mode & S_IXOTH) != 0) ? my_putstr("x") : my_putstr("-");
}
