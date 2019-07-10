/*
** my_str_islower.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_13
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 17:04:22 2015 Kamil Marque
** Last update Tue Oct  6 10:05:42 2015 Kamil Marque
*/

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 97 && str[i] <= 122))
        i++;
      else
        return (0);
    }
  return (1);
}
