/*
** my_getnbr.c for  in /home/marque_p/rendu/CPE_2015_n4s/kamel
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Thu May 26 21:15:32 2016 kamil
** Last update Thu May 26 21:15:40 2016 kamil
*/

int     my_getnbr(char *str)
{
  int   neg;
  long  res;

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
      else        return (res * neg);
    }
  return (res * neg);
}
