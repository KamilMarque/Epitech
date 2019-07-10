/*
** my_revstr.c for  in /home/marque_p/rendu/Piscine_C_J06
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 09:22:08 2015 Kamil Marque
** Last update Mon Oct  5 09:40:02 2015 Kamil Marque
*/

char	*my_revstr(char *str)
{
  int	i;
  int	a;
  char	b;

  i = 0;
  while (str[i] != '\0')
    i++;
  i--;
  a = i;
  i = 0;
  while (i < a)
    {
      b = str[i];
      str[i] = str[a];
      str[a] = b;
      i++;
      a--;
    }
  return (str);
}
