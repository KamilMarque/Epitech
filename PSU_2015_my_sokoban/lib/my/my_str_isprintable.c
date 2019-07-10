/*
** my_str_isprintable.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_15
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 17:09:05 2015 Kamil Marque
** Last update Mon Oct  5 17:10:45 2015 Kamil Marque
*/

int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 0 && str[i] <= 31)
        i++;
      else
        return (0);
    }
  return (1);
}
