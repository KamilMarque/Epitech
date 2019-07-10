/*
** my_strcapitalize.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_10
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 16:06:42 2015 Kamil Marque
** Last update Mon Oct  5 17:32:56 2015 Kamil Marque
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  if (str[i] < 122 && str[i] > 97)
    str[i] = str[i] - 32;
  while (str[i] != '\0')
    {
      if (str[i] == ' ' && (str[i + 1] <= 122 && str[i + 1] >= 97))
	{
	  i++;
	  str[i] = str[i] - 32;
	}
      else if (str[i] == '+' && (str[i + 1] <= 122 && str[i + 1] >= 97))
	{
	  i++;
	  str[i] = str[i] - 32;
	}
      else
	i++;
    }
  return (str);
}
