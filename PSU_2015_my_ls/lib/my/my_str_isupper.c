/*
** my_str_isupper.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_14
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 17:06:04 2015 Kamil Marque
** Last update Mon Oct  5 17:11:18 2015 Kamil Marque
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
        i++;
      else
        return (0);
    }
  return (1);
}
