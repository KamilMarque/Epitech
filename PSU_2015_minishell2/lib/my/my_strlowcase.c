/*
** my_strlowcase.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_09
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 15:54:25 2015 Kamil Marque
** Last update Mon Oct  5 16:03:19 2015 Kamil Marque
*/

char    *my_strlowcase(char *str)
{
  int   i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] >= 65 && str[i] <= 90)
      str[i] = str[i] + 32;
  return (str);
}
