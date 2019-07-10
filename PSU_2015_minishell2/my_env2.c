/*
** my_env2.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Mar 19 01:31:48 2016 Kamil Marque
** Last update Sun Apr  3 18:06:24 2016 kamil
*/

#include "my.h"

char    *my_supp_env_tab2(t_mini *mini, char **tmp, char **tmp2, int len)
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

char    *my_supp_env_tab(t_mini *mini, int len, int i, int j)
{
  char  **tmp;
  char  **tmp2;
  int   x;

  while (mini->before[len++]);
  if ((tmp = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  if ((tmp2 = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  x = -1;
  while (mini->before[++x])
    {
      if (my_check_cmp(mini->before[x], mini->valid_tab[i]) != 1)
	{
	  tmp[j] = my_strdup(mini->before[x]);
	  tmp2[j++] = my_strdup(mini->after[x]);
	}
    }
  tmp[j] = NULL;
  tmp2[j] = NULL;
  my_supp_env_tab2(mini, tmp, tmp2, len);
}

void	my_supp_env(t_mini *mini)
{
  int   x;
  int	i;

  i = 1;
  while (mini->valid_tab[i])
    {
      x = 0;
     while (mini->before[x])
	{
	  if (my_check_cmp(mini->before[x], mini->valid_tab[i]) == 1)
	    my_supp_env_tab(mini, 0, i, 0);
	  x++;
	}
       i++;
    }
}
