/*
** main.c for  in /home/marque_p/rendu/PSU_2015_my_printf
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Nov  3 11:33:42 2015 Kamil Marque
** Last update Mon Nov 16 19:29:20 2015 Kamil Marque
*/

#include <stdarg.h>
#include <stdio.h>

void    my_check(va_list ap, const char *format, int i)
{
  int	c;

  c = 0;
  if (format[i] == 'c')
    my_putchar(va_arg(ap, int));
  else if (format[i] == 'd' || format[i] == 'i')
    my_put_nbr(va_arg(ap, int));
  else if (format[i] == 's')
    my_putstr(va_arg(ap, char *));
  else if (format[i] == 'x')
    my_put_nbr_base_unsigned(va_arg(ap, unsigned int), "0123456789abcdef");
  else if (format[i] == 'X')
    my_put_nbr_base_unsigned(va_arg(ap, unsigned int), "0123456789ABCDEF");
  else if ((format[i] == '%'))
      my_putchar('%');
  else if (format[i] == 'p')
    find_my_adress(ap);
  else if (format[i] == 'o')
    my_put_nbr_base_unsigned(va_arg(ap, unsigned int), "01234567");
  else if (format[i] == 'b')
    my_put_nbr_base_unsigned(va_arg(ap, unsigned int), "01");
  else if (format[i] == 'u')
    my_put_nbr_unsigned(va_arg(ap, unsigned int));
  else if (format[i] == 'S')
    my_spe_putstr(va_arg(ap, unsigned char *));
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;

  i = 0;
  va_start(ap, format);
  while (format[i] != 0)
    {
      if (format[i] == '%')
	{
	  i++;
	  while (format[i] == ' ')
	    i++;
	  my_check(ap, format, i);
	}
      else
      	my_putchar(format[i]);
      i++;
    }
  va_end(ap);
}
