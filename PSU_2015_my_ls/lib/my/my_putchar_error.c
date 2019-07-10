/*
** my_putchar_error.c for  in /home/marque_p/rendu/PSU_2015_my_ls/lib/my
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Nov 25 19:44:03 2015 Kamil Marque
** Last update Wed Nov 25 19:46:02 2015 Kamil Marque
*/

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar_error(str[i]);
      i++;
    }
}
