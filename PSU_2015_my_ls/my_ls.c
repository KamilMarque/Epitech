/*
** my_ls.c for  in /home/marque_p/rendu/PSU_2015_my_ls
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Nov 25 17:03:13 2015 Kamil Marque
** Last update Sun Nov 29 21:26:21 2015 Kamil Marque
*/

#include "my.h"

void	my_l(t_list *racine, t_check *check)
{
  DIR           *dir;
  struct passwd	*user;
  struct group	*grp;
  struct dirent *dire;
  struct stat   st;
  mode_t	st_mode;
  gid_t		gid;
  t_list	*tmp;

  user = getpwuid(st.st_uid);
  grp = getgrgid(st.st_gid);
}

void	my_just_options(t_list *racine, t_check *ch, t_list *racine2)
{
  t_list	*tmp;

  tmp = racine->next;
  if (ch->d == 1)
    my_d(racine, ch);
  if (ch->r == 1)
    my_r(racine, ch);
  if (ch->l == 0 && ch->r == 0 && ch->d == 0 && ch->t == 0 && ch->big_r == 0)
    my_no_op(racine, racine2);
}

void	my_ls(t_list *racine, t_check *check, t_list *racine2)
{
  t_list	*tmp;
  DIR		*dire;

  tmp = racine->next;
  racine = my_trie(racine, racine2);
  my_just_options(racine, check, racine2);
}

int	main(int ac, char **av)
{
  int		i;
  t_list	*racine;
  t_list	*racine2;
  t_check	check;

  i = 0;
  ini_check(&check);
  racine = my_create_list(racine);
  racine2 = my_create_list(racine2);
  if (ac == 1)
    my_basic_ls(racine, racine2);
  else
    {
      my_save(ac , av, racine, &check);
      my_ls(racine, &check, racine2);
    }
  return (0);
}
