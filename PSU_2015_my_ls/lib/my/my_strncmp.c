/*
** my_strncmp.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_07
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 14:39:07 2015 Kamil Marque
** Last update Tue Oct  6 10:02:22 2015 Kamil Marque
*/

int	my_check(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  if (my_check(s1) > nb && my_check(s2) > nb)
    {
      while (i < nb)
	{
	  if (s1[i] == s2[i])
	    {
	      i++;
	      if (i == nb)
		return (0);
	    }
	  else
	    return (s1[i] - s2[i]);
	}
    }
  else
    return (s1[i] - s2[i]);
  return (-1);
}
