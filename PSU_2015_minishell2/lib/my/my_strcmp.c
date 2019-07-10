/*
** my_strcmp.c for  in /home/marque_p/rendu/Piscine_C_J06/ex_06
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Oct  5 14:26:02 2015 Kamil Marque
** Last update Wed Mar 16 18:44:54 2016 Kamil Marque
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	res;

  i = 0;
  res = 0;
  while (s1[i] == s2[i])
    {
      if (s1 == '\0' && s2 == '\0')
	return (1);
      i++;
    }
  if (s1[i] != s2[i])
    res = s1[i] - s2[i];
  return (res);
}
