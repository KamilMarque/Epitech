/*
** my_strstr.c for  in /home/marque_p/rendu/Piscine_C_J06
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 09:40:41 2015 Kamil Marque
** Last update Mon Oct  5 11:25:26 2015 Kamil Marque
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  if (str[0] != '\0')
    {
      i = -1;
      while (to_find[++i] != '\0')
	{
	  if (to_find[i] != str[i])
	    return (my_strstr(str + 1, to_find));
	  return (str);
	}
    }
  else
    return (0);
}
