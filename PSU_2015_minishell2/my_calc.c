/*
** my_calc.c for  in /home/marque_p/rendu/PSU_2015_minishell1
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Mar 19 01:27:51 2016 Kamil Marque
** Last update Sat Mar 19 01:29:33 2016 Kamil Marque
*/

#include "my.h"

void            my_aff_tab(t_mini *mini)
{
  int           x;

  x = 0;
  while (mini->before[x])
    {
      my_putstr(mini->before[x]);
      my_putchar('=');
      my_putstr(mini->after[x]);
      my_putchar('\n');
      x++;
    }
}

int             my_calc_env(char **env)
{
  int           x;

  x = 0;
  while (env[x])
    x++;
  return (x + 1);
}

int             my_sp_strlen(char *str, char sep)
{
  int           i;

  i = 0;
  while (str[i] != sep)
    i++;
  return (i);
}

int             my_strlen_end(char *str)
{
  int           i;
  int           x;

  x = 0;
  i = 0;
  while (str[i] != '=')
    i++;
  while (str[i])
    {
      i++;
      x++;
    }
  return (x);
}
