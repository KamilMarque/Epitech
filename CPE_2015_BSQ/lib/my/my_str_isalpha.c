/*
** my_str_isalpha.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_11
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 16:56:05 2015 Kamil Marque
** Last update Mon Oct  5 16:57:48 2015 Kamil Marque
*/

int     my_str_isalpha(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <= 90))
        i++;
      else
        return (0);
    }
  return (1);
}
