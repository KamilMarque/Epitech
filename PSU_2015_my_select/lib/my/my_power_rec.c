/*
** my_power_rec.c for  in /home/marque_p/rendu/Piscine_C_J05
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 10:40:41 2015 Kamil Marque
** Last update Mon Oct  5 10:42:19 2015 Kamil Marque
*/

int	my_power_rec(int nb, int power)
{
  int	res;

  res = nb;
  if (power == 0)
    return (1);
  else if (power < 0)
    return (0);
  else if (power == 1)
    return (nb);
  else
    res = res * my_power_rec(nb, power - 1);
  return (res);
}
