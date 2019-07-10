/*
** my_strdup.c for  in /home/marque_p/rendu/PSU_2015_my_select
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Feb 24 04:59:11 2016 Kamil Marque
** Last update Wed Feb 24 06:02:29 2016 Kamil Marque
*/

#include "my_strdup.h"

char	*my_strdup(char *src)
{
  char	*res;

  if (src == NULL)
    return (NULL);
  if ((res = malloc(sizeof(char) * my_strlen(src))) == NULL)
    return (NULL);
  res = my_strcpy(res, src);
  return (res);
}
