/*
** my_fonction.c for  in /home/marque_p/rendu/PSU_2015_my_printf
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Nov  3 15:01:18 2015 Kamil Marque
** Last update Mon Nov 16 17:13:25 2015 Kamil Marque
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int    find_my_adress(va_list ap)
{
  void  *adress;

  adress = va_arg(ap, void*);
  if (adress == NULL)
    {
      write(1, "(nil)", 6);
      return (1);
    }
  my_putstr("0x");
  my_put_nbr_base_long((unsigned long)adress, "0123456789abcdef");
}

int     my_put_nbr_base_long(unsigned long nb, char *base)
{
  if (nb < my_strlen(base))
    my_putchar(base[nb]);
  else
    {
      my_put_nbr_base_long(nb / my_strlen(base), base);
      my_put_nbr_base_long(nb % my_strlen(base), base);
    }
}

void    my_put_nbr_unsigned(unsigned int nb)
{
  if (nb < 10)
    my_putchar(nb + 48);
  else
    {
      my_put_nbr_unsigned(nb / 10);
      my_put_nbr_unsigned(nb % 10);
    }
}

int     my_put_nbr_base_unsigned(unsigned int nb, char *base)
{
  if (nb < my_strlen(base))
    my_putchar(base[nb]);
  else
    {
      my_put_nbr_base_unsigned(nb / my_strlen(base), base);
      my_put_nbr_base_unsigned(nb % my_strlen(base), base);
    }
}

int	my_spe_putstr(unsigned char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    {
      write(1, "(null)", 7);
      return (1);
    }
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  if (str[i] <= 7)
	    my_putstr("00");
	  else if (str[i] > 7 && str[i] < 32)
	    my_putchar('0');
	  my_put_nbr_base(str[i], "01234567");
	}
      else
	my_putchar(str[i]);
      i++;
    }
}
