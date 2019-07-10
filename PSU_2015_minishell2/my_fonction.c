/*
** my_fonction.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Mar 19 01:46:54 2016 Kamil Marque
** Last update Sun Apr  3 19:12:23 2016 kamil
*/

#include "my.h"

void            my_execu(t_mini *mini, char **env)
{
  pid_t         pid;
  int           status;

  pid = fork();
  if (pid == 0)
    {
      if (execve(mini->valid_tab[0], mini->valid_tab, env) == -1)
	exit (1);
    }
  else    waitpid(0, &status, WUNTRACED);
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	my_putstr("Segmentation Fault\n");
      else if (WTERMSIG(status) == 8)
	my_putstr("Floating point exception\n");
    }
}

int             my_check_cmp(char *s1, char *s2)
{
  int           i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}

char            *my_cd_user(t_mini *mini)
{
  int           x;
  char          *my_home;
  char		buf[50];

  x = 0;
  while (mini->before[x] != NULL)
    if (my_check_cmp(mini->before[x], "HOME") == 1)
      {
	if (mini->after[x] == NULL)
	  return (NULL);
	if ((mini->my_user = malloc(sizeof(char) *
				    (my_strlen(mini->after[x]) + 1))) == NULL)
	  return (NULL);
	mini->cd_less = my_strdup(getcwd(buf, 50));
	my_strcpy(mini->my_user, mini->after[x]);
	chdir(mini->my_user);
	return (NULL);
      }
    else
      x++;
}

int             my_check_nb(t_mini *mini)
{
  int           x;

  x = 0;
  if (mini->valid_tab[1] == NULL)
    return (0);
  while (mini->valid_tab[1][x])
    {
      if (mini->valid_tab[1][x] < '0' || mini->valid_tab[1][x] > '9')
	return (0);
      x++;
    }
  return (1);
}
