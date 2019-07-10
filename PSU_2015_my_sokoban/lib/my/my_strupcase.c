/*
** my__strupcase.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_08
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 15:40:45 2015 Kamil Marque
** Last update Mon Oct  5 16:04:18 2015 Kamil Marque
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] >= 97&& str[i] <= 122)
      str[i] = str[i] - 32;
  return (str);
}
