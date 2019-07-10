/*
** my_swap.c for  in /home/marque_p/rendu/Piscine_C_J04
** 
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
** 
** Started on  Thu Oct  1 08:52:53 2015 Kamil Marque
** Last update Thu Oct  1 08:54:04 2015 Kamil Marque
*/

int     my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
