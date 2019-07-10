/*
** my_cd_less.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Mar 19 15:46:19 2016 Kamil Marque
** Last update Sat Mar 19 16:30:37 2016 Kamil Marque
*/

#include "my.h"

char		*my_supp_oldpwd(t_mini *mini, char **tmp, char **tmp2, int len)
{
  int   x;

  x = 0;
  if ((mini->before = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  if ((mini->after = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  while (tmp[x])
    {
      mini->before[x] = my_strdup(tmp[x]);
      mini->after[x] = my_strdup(tmp2[x]);
      x++;
    }
  mini->before[x] = NULL;
  mini->after[x] = NULL;
}

char		*my_supp_oldpwd(t_mini *mini, int len, int i, int j)
{
  char		**tmp;
  char		**tmp2;
  int		x;

  while (mini->before[len++]);
  if ((tmp = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  if ((tmp2 = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  while (mini->valid_tab[(++i)])
    {
      x = -1;
      while (mini->before[++x])
	{
	  tmp[j] = my_strdup(mini->before[x]);
	  if (my_check_cmp(mini->before[x], "OLDPWD") != 1)
	    tmp2[j] = my_strdup(mini->after[x]);
	  else
	    tmp2[j] = my_strdup("");
	  j++;
	}
      tmp[j] = NULL;
      tmp2[j] = NULL;
      my_supp_env_tab2(mini, tmp, tmp2, len);
    }
}

void		my_check_oldpwd(t_mini *mini)
{
  int		x;
  char		*last_pwd;
  int		k;

  k = 0;
  x = -1;
  while (mini->before[++x])
    if (my_check_cmp(mini->before[x], "PWD") == 1)
      {
	last_pwd = my_strdup(mini->after[x]);
	k = 1;
      }
  if (k = 1)
    {
      my_putstr("PWD is not exist in env");
      return (-1);
    }
  x = -1;
  while (mini->before[++x])
    if (my_check_cmp(mini->before[x], "OLDPDW") != 1)
      mini->after[x] = my_strdup(last_pwd);
}
