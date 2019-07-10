/*
** my_str_isnum.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_12
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 17:01:16 2015 Kamil Marque
** Last update Tue Oct  6 10:03:16 2015 Kamil Marque
*/

int     my_str_isnum(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9'))
        i++;
      else
        return (0);
    }
  return (1);
}
