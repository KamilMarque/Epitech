/*
** getnextl.c for  in /home/henry_g/rendu/get_next_line
**
** Made by Clément Henry
** Login   <henry_g@epitech.net>
**
** Started on  Sun Jan  3 00:04:08 2016 Clément Henry
** Last update Fri May 27 23:13:40 2016 kamil
*/

# include "get_next_line.h"

int		len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int		check_read(char *stat_line)
{
  int	cpt;

  cpt = 0;
  if (stat_line == NULL)
    return (0);
  while (stat_line[cpt] != '\0')
    {
      if (stat_line[cpt] == '\n')
	return (1);
      cpt++;
    }
  return (0);
}

char		*my_realloc(char *s_1, char *s_2)
{
  char	*str;
  int	i;
  int	c;

  i = 0;
  c = 0;
  if (s_1 == NULL)
    {
      if ((str = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
	return (NULL);
      while (s_2[i] != '\0')
	str[c++] = s_2[i++];
    }
  else
    {
      if ((str = malloc((len(s_2) + len(s_1) + 1) * sizeof(char))) == NULL)
	return (NULL);
      while (s_1[i] != '\0')
	str[c++] = s_1[i++];
      i = 0;
      while (s_2[i] != '\0')
	str[c++] = s_2[i++];
    }
  str[c] = '\0';
  return (str);
}

char		*copy_backslash(char *buff)
{
  char		*tmp;
  int		i;
  static int	cpt = 0;

  i = 0;
  if ((tmp = malloc((len(buff) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (buff[cpt] != '\n')
    tmp[i++] = buff[cpt++];
  buff[cpt] = '8';
  cpt = cpt + 1;
  tmp[i] = '\0';
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static int	cpt = 0;
  static char	*buff = NULL;
  char		*final;
  char		*tmp;
  int		size;

  if ((tmp = malloc((READ_SIZE + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (check_read(buff) != 1)
    {
      if ((size = read(fd, tmp, READ_SIZE)) == -1)
	return (NULL);
      tmp[READ_SIZE] = '\0';
      buff = my_realloc(buff, tmp);
      if (size == 0)
	return (NULL);
    }
  final = copy_backslash(buff);
  return (final);
}
