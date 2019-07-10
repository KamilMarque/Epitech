/*
** my_put_nbr.c for  in /home/marque_p/rendu/Piscine_C_J03
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Wed Sep 30 12:41:08 2015 Kamil Marque
** Last update Tue Oct  6 09:21:18 2015 Kamil Marque
*/

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
