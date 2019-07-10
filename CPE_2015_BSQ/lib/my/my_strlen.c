/*
** my_strlen.c for  in /home/marque_p/rendu/Piscine_C_J04
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Thu Oct  1 08:58:57 2015 Kamil Marque
** Last update Thu Oct  1 17:52:47 2015 Kamil Marque
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      i++;
  return (i);
}
