/*
** my_path.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Mar 19 01:38:17 2016 Kamil Marque
** Last update Sun Apr  3 17:55:46 2016 kamil
*/

#include "my.h"

int             find_my_path(t_mini *mini)
{
  int           x;
  int           y;

  x = 0;
  while (mini->before[x])
    {
      if (mini->before[x][0] == 'P' && mini->before[x][1] == 'A'
	            && mini->before[x][2] == 'T' && mini->before[x][3] == 'H'
	  && mini->before[x][4] == 0)
	{
	  return (x);
	}
      else
	x++;
    }
  return (-5);
}

void            my_path_default(t_mini *mini)
{
  mini->path = my_strdup("/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:");
}

char            *find_my_path2(t_mini *m)
{
  int           x;

  x = find_my_path(m);
  if (x != -5)
    {
      m->path = my_strdup("/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:");
      return (m->path);
    }
  my_path_default(m);
}

char            *my_acces(t_mini *mini)
{
  int           x;

  x = 0;
  while (mini->tab_path[x])
    {
      my_strdup(mini->tab_path[x] = my_strcat(mini->tab_path[x], "/"));
      mini->tab_path[x] = my_strdup(my_strcat(mini->tab_path[x],
					      mini->valid_tab[0]));
      if (access(mini->tab_path[x], F_OK) == 0)
	{
	  mini->good_path = mini->tab_path[x];
	  return (mini->good_path);
	}
      x++;
    }
  mini->good_path == NULL;
  my_putstr(mini->valid_tab[0]);
  my_putstr(": Command not found.\n");
  return (NULL);
}

void            my_fork(t_mini *mini, char **env)
{
  pid_t         pid;
  int           status;

  pid = fork();
  if (pid == 0)
    {
      if (execve(mini->good_path, mini->valid_tab, env) == -1)
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
