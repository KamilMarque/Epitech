/*
** serveur.c for  in /home/marque_p/rendu/PSU/PSU_2015_minitalk
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb  3 16:05:24 2016 Kamil Marque
** Last update Sat Feb 13 18:30:05 2016 Kamil Marque
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb < 10)
    my_putchar(nb + 48);
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
}

void	my_serveur(int sig)
{
  static int	i = 0;
  static int	c = 0;

  if (sig == SIGUSR1)
    sig = 0;
  else if (sig == SIGUSR2)
    sig = 1;
  c = c + (sig << i++);
  if (i == 8)
    {
      my_putchar(c);
      i = 0;
      c = 0;
    }
}

int	main(int ac, char **av)
{
  pid_t	pid;

  pid = getpid();
  my_put_nbr(pid);
  my_putchar('\n');
  while (42)
    {
      if ((signal(SIGUSR1, my_serveur)) == SIG_ERR)
	return (-1);
      else if ((signal(SIGUSR2, my_serveur)) == SIG_ERR)
	return (-1);
    }
}
