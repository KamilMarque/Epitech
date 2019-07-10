/*
** my_is_prime.c for  in /home/marque_p/rendu/Piscine_C_J05
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 10:18:54 2015 Kamil Marque
** Last update Fri Oct  9 19:22:09 2015 Kamil Marque
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb == 0 || nb == 1)
    return (0);
  if (nb > 0)
    {
      while (i != nb)
	{
	  if (nb % i == 0)
	    return (0);
	  i++;
	}
      return (i);
    }
  else
    return (i);
}
