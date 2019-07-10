/*
** my_check.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Mar 19 01:33:49 2016 Kamil Marque
** Last update Sun Apr  3 19:21:13 2016 kamil
*/

#include "my.h"

int             my_check_arg2(t_mini *mini, char **env)
{
  if (my_check_cmp(mini->valid_tab[0], "setenv") == 1)
    {
      if (mini->valid_tab[1] != NULL)
	my_setenv(mini);
      else
	my_aff_tab(mini);
      return (1);
    }
  else if (my_check_cmp(mini->valid_tab[0], "unsetenv") == 1)
    {
      if (mini->valid_tab[1] != NULL)
	my_supp_env(mini);
      return (1);
    }
  else if (my_check_cmp(mini->valid_tab[0], "env") == 1)
    {
      my_aff_tab(mini);
      return (1);
    }
  else if (mini->valid_tab[0][0] == '.' || mini->valid_tab[0][0] == '/')
    {
      my_execu(mini, env);
      return (1);
    }
}

int		my_cd_less(t_mini *mini, char **env)
{
  char		buf[50];
  char		tmp[50];

  if (mini->valid_tab[1] != NULL
      && my_check_cmp(mini->valid_tab[1], "--") != 1
      && my_check_cmp(mini->valid_tab[1], "-") != 1)
    {
      mini->cd_less = my_strdup(getcwd(buf, 50));
      chdir(mini->valid_tab[1]);
    }
  else if (mini->valid_tab[1] != NULL
	   && my_check_cmp(mini->valid_tab[1], "-") == 1)
    {
      if (mini->cd_less == NULL)
	return (1);
      getcwd(tmp, 50);
      chdir(mini->cd_less);
      mini->cd_less = my_strdup(tmp);
    }
  else
    my_cd_user(mini);
  return (1);
}

int             my_check_arg(t_mini *mini, char **env)
{
  if (my_check_cmp(mini->valid_tab[0], "cd") == 1)
    {
      if (my_cd_less(mini, env) == 1)
	return (1);
    }
  else if (my_check_cmp(mini->valid_tab[0], "exit") == 1)
    {
      if (my_check_nb(mini) == 1)
	exit (my_getnbr(mini->valid_tab[1]));
      else
	exit (0);
      return (1);
    }
  else if (my_check_arg2(mini, env) == 1)
    return (1);
}

int             check_space(char *str)
{
  int           i;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ')
	return (0);
      i++;
    }
  return (1);
}

void            my_check_arg_null(char *arg)
{
  if (arg == NULL)
    {
      my_putstr("exit\n");
      exit(0);
    }
}
