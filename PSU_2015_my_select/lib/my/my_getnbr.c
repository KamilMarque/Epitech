/*
** my_getnbr.c for  in /home/marque_p/rendu/Piscine_C_J04
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Thu Oct  1 09:46:39 2015 Kamil Marque
** Last update Thu Oct  1 19:59:28 2015 Kamil Marque
*/

int	my_getnbr(char *str)
{
  int	neg;
  long	res;

  neg = 1;
  res = 0;
  while (*str == '+' || *str == '-')
    {
      if (*str == '-')
	  neg = neg * -1;
      str++;
    }
  while (*str != '\0')
    {
      if (*str <= '9' && *str >= '0')
	{
	  res = res * 10;
	  res = res + *str - 48;
	  if (((res * neg) > 2147483647) || ((res * neg) < -2147483648))
	    return (0);
	  str++;
	}
      else
	return (res * neg);
    }
  return (res * neg);
}
