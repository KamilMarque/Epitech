/*
** client.c for  in /home/marque_p/rendu/PSU/PSU_2015_minitalk
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Mon Feb  8 14:55:07 2016 Kamil Marque
** Last update Sat Feb 13 18:12:04 2016 Kamil Marque
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

int		my_getnbr(char *str)
{
  int		neg;
  long		res;

  neg = 1;
  res = 0;
  while (*str == '+' || *str == '-')
    {
      if (*str == '-')
	neg = neg * -1;
      str++;
    }
  while (*str != '\0')
    {
      if (*str <= '9' && *str >= '0')
	{
	  res = res * 10;
	  res = res + *str - 48;
	  if (((res * neg) > 2147483647) || ((res * neg) < -2147483648))
	    return (0);
	  str++;
	}
      else
	return (res * neg);
    }
  return (res * neg);
}

void		my_sleep_sig(int pid, int gu)
{
  if (gu == 1)
    {
      kill(pid, SIGUSR1);
      usleep(5);
    }
  else
    {
      kill(pid, SIGUSR2);
      usleep(5);
    }
}

char		my_bi(int pid, char *str)
{
  static int	i = 0;
  int		res;
  int		new_i;
  int		my_zero;

  my_zero = 0;
  new_i = str[i];
  while (new_i > 0)
    {
      res = new_i % 2;
      if (res == 0)
	my_sleep_sig(pid, 1);
      else if (res == 1)
	my_sleep_sig(pid, 2);
      new_i = new_i / 2;
      my_zero++;
    }
  while (my_complet_zero(my_zero, pid) != 1)
    my_zero++;
  if (str[++i] != 0)
    {
      my_bi(pid, str);
      my_zero = 0;
    }
}

int		my_complet_zero(int my_zero, int pid)
{
  if (my_zero == 0)
    my_sleep_sig(pid, 1);
  else if (my_zero == 1)
    my_sleep_sig(pid, 1);
  else if (my_zero == 2)
    my_sleep_sig(pid, 1);
  else if (my_zero == 3)
    my_sleep_sig(pid, 1);
  else if (my_zero == 4)
    my_sleep_sig(pid, 1);
  else if (my_zero == 5)
    my_sleep_sig(pid, 1);
  else if (my_zero == 6)
    my_sleep_sig(pid, 1);
  else if (my_zero == 7)
    my_sleep_sig(pid, 1);
  else if (my_zero == 8)
    return (1);
}

int		main(int ac, char **av)
{
  if (ac == 3 && my_getnbr(av[1]) > 0)
    my_bi(my_getnbr(av[1]), av[2]);
}
