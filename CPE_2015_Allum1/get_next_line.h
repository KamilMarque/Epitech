/*
** get_next_line.h for  in /home/marque_p/rendu/CPE_2015_getnextline
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Jan  5 16:38:40 2016 Kamil Marque
** Last update Thu Jan 14 18:07:36 2016 Kamil Marque
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef READ_SIZE
#define READ_SIZE (1000)

typedef struct	s_str
{
  int		c;
  char		*buf;
  char		*res;
}		t_str;

#endif /* !READ_SIZE */
