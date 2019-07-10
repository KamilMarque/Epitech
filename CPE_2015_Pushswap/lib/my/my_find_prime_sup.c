/*
** my_is_prime_sup.c for  in /home/marque_p/rendu/Piscine_C_J05
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 10:30:40 2015 Kamil Marque
** Last update Fri Oct  9 19:22:20 2015 Kamil Marque
*/

int	my_find_prime_sup(int nb)
{
  while (my_is_prime(nb) == 0)
    nb++;
  return (nb);
}
