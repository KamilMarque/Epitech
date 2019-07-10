/*
** main.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Mon Mar 14 16:11:33 2016 Kamil Marque
** Last update Sun Apr  3 19:12:20 2016 kamil
*/

#include "my.h"

char		*my_valid_arg(char *str, t_mini *mini)
{
  char		*tmp;
  int		i;
  int		j;

  j = 0;
  i = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
     return (NULL);
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  if (i != 0 && str[i - 1] != ';')
	    tmp[j++] = ' ';
	  while ((str[i] == ' ' || str[i] == '\t'))
	    i++;
	  if (str[i] == 0)
	    tmp[j++] = 0;
	}
      else
	tmp[j++] = str[i++];
    }
  if (str == NULL)
    tmp = NULL;
  mini->mult = str_to_wordtab(tmp, ';');
}

void		my_signal()
{
  my_putstr("\n$>");
}

void		my_while(t_mini *mini, int x, char **env)
{
  find_my_path2(mini);
  mini->tab_path = str_to_wordtab(mini->path, ':');
  mini->valid_tab = str_to_wordtab(mini->mult[x], ' ');
  if (my_check_cmp(mini->mult[x], "") == 1);
  else if (my_check_arg(mini, env) != 1)
    {
      if (my_acces(mini) != NULL)
	my_fork(mini, env);
    }
}

int		main(int ac, char **av, char **env)
{
  t_mini	mini;
  char		*arg;
  int		x;

  mini.cd_less = NULL;
  signal(SIGINT, my_signal);
  my_cut_env(env, &mini);
  my_cut_env_end(env, &mini);
  while (42)
    {
      x = 0;
      my_putstr("$>");
      arg = get_next_line(0);
      my_check_arg_null(arg);
      if (my_check_cmp(arg, "") != 1)
	if (check_space(arg) != 1)
	  {
	    my_valid_arg(arg, &mini);
	    while (mini.mult[x])
	      {
		my_while(&mini, x, env);
		x++;
	      }
	  }
    }
}
