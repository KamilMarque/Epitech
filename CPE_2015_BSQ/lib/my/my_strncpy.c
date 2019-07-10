/*
** my_strncpy.c for  in /home/marque_p/rendu/Piscine_C_J06
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 09:17:20 2015 Kamil Marque
** Last update Thu Dec  3 20:56:26 2015 Kamil Marque
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (i < nb && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
