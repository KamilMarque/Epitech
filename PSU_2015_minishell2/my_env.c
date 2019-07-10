/*
** my_env.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Mar 19 01:29:42 2016 Kamil Marque
** Last update Tue Mar 29 16:29:41 2016 kamil
*/

#include "my.h"

char            *my_cut_env(char **env, t_mini *mini)
{
  int           x;
  int           y;
  int           i;

  x = 0;
  i = my_calc_env(env);
  if ((mini->before = malloc(sizeof(char *) * (i))) == NULL)
    return (NULL);
  if ((mini->after = malloc(sizeof(char *) * (i))) == NULL)
    return (NULL);
  if (i = 1)
    mini->before[0] = NULL;
  while (env[x] != NULL)
    {
      i = my_sp_strlen(env[x], '=');
      if ((mini->before[x] = malloc(sizeof(char) * (i + 1))) == NULL)
	return (NULL);
      y = 0;
      while (env[x][y] != '=')
	mini->before[x][y] = env[x][y++];
      mini->before[x][y] = '\0';
      x++;
    }
  mini->before[x] = NULL;
}
char            *my_cut_env_end(char **env, t_mini *mini)
{
  int           x;
  int           y;
  int           i;
  int           tmp;

  x = 0;
  while (env[x])
    {
      tmp = 0;
      y = my_sp_strlen(env[x], '=') + 1;
      i = my_strlen_end(env[x]);
      if ((mini->after[x] = malloc(sizeof(char) * (i + 2))) == NULL)
	return (NULL);
      while (env[x][y] != 0)
	mini->after[x][tmp++] = env[x][y++];
      mini->after[x][tmp] = '\0';
      x++;
    }
  mini->after[x] = NULL;
}

char            *my_add_env2(t_mini *mini, char **tmp, char **tmp2, int len)
{
  int           x;

  x = 0;
  if ((mini->after = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  if ((mini->before = malloc(sizeof(char *) * (len + 2))) == NULL)
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

char            *my_add_env(t_mini *mini)
{
  char          **tmp;
  char          **tmp2;
  int           x;
  int           len;

  len = 0;
  x = 0;
  while (mini->before[len++]);
  if ((tmp = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  if ((tmp2 = malloc(sizeof(char *) * (len + 2))) == NULL)
    return (NULL);
  while (mini->before[x])
    {
      tmp[x] = my_strdup(mini->before[x]);
      tmp2[x] = my_strdup(mini->after[x++]);
    }
  tmp[x] = my_strdup(mini->valid_tab[1]);
  if (mini->valid_tab[2] != NULL)
    tmp2[x] = my_strdup(mini->valid_tab[2]);
  else
    tmp2[x] = my_strdup("\0");
  tmp[x + 1] = NULL;
  tmp2[x + 1] = NULL;
  my_add_env2(mini, tmp, tmp2, len);
}

int             my_setenv(t_mini *mini)
{
  int           x;

  x = 0;
  while (mini->before[x])
    {
      if (my_check_cmp(mini->before[x], mini->valid_tab[1]) == 1)
	{
	  if (mini->valid_tab[2] != NULL)
	    {
	      mini->after[x] = my_strdup(mini->valid_tab[2]);
	      return (1);
	    }
	  else
	    {
	      mini->after[x] = my_strdup("\0");
	      return (1);
	    }
	}
      x++;
    }
  my_add_env(mini);
}
