/*
** my_square_root.c for  in /home/marque_p/rendu/Piscine_C_J05
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 10:38:26 2015 Kamil Marque
** Last update Tue Oct  6 10:01:40 2015 Kamil Marque
*/

int	my_square_root(int nb)
{
  int	i;

  i = 0;
  while (i <= 46340)
    {
      if (i * i == nb)
	return (i);
      i++;
    }
  return (0);
}
