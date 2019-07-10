/*
** my_strcpy.c for  in /home/marque_p/rendu/Piscine_C_J06
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 09:06:19 2015 Kamil Marque
** Last update Wed Feb 24 06:00:48 2016 Kamil Marque
*/

#include "my_strdup.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
