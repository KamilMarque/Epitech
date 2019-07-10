/*
** my_put_nbr_base.c for  in /home/marque_p/rendu/PSU_2015_my_printf/lib/my
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Nov  3 11:56:16 2015 Kamil Marque
** Last update Thu Nov 12 18:12:50 2015 Kamil Marque
*/

int     my_put_nbr_base(int nb, char *base)
{
  if (nb < my_strlen(base))
    my_putchar(base[nb]);
  else
    {
      my_put_nbr_base(nb / my_strlen(base), base);
      my_put_nbr_base(nb % my_strlen(base), base);
    }
}
