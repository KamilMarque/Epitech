/*
** get_next_line.c for  in /home/marque_p/rendu/CPE_2015_getnextline
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Tue Jan  5 16:29:36 2016 Kamil Marque
** Last update Sat Apr  2 18:53:47 2016 kamil
*/

#include "get_next_line.h"

char		*my_save(char *buf, char *save, int count)
{
  int		cpt1;
  int		cpt2;
  char		*tmp;

  cpt1 = 0;
  cpt2 = 0;
  buf[count] = 0;
  if (save != NULL)
    {
      if ((tmp = malloc(sizeof(char) * (my_strlen(buf)
					+ my_strlen(save) + 1))) == NULL)
	return (NULL);
      while (save[cpt1] != 0)
	tmp[cpt2++] = save[cpt1++];
    }
  else
    if ((tmp = malloc(sizeof(char) * (my_strlen(buf) + 1))) == NULL)
      return (NULL);
  cpt1 = 0;
  while (buf[cpt1] != 0)
    tmp[cpt2++] = buf[cpt1++];
  tmp[cpt2] = 0;
  return (tmp);
}

int		my_check(char *save)
{
  int		i;

  i = 0;
  while (save[i])
    {
      if (save[i++] == '\n')
	return (1);
    }
  return (0);
}

int		my_init(int *j, int *i, char *save, char *res)
{
  res[*j] = 0;
  *j = 0;
  if (save[*i] != 0)
    {
      save[*i] = 'p';
      *i = *i + 1;
    }
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	*s = NULL;
  static int	i = 0;
  static int	j = 0;
  t_str		str;

  if ((str.buf = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if (((str.c = read(fd, str.buf, READ_SIZE)) < 1) && (s == NULL || s[i] == 0))
    return (NULL);
  s = my_save(str.buf, s, str.c);
  if (my_check(s) == 0 && str.c != 0)
      get_next_line(fd);
  else
    {
      if ((str.res = malloc(sizeof(char) * my_strlen(s) + 1)) == NULL)
         return (NULL);
      while ((s)[i] != '\n')
      	{
	  if ((s)[i] == 0)
	    return (str.res);
	  (str.res)[j++] = (s)[i++];
      	}
      return (my_init(&j, &i, s, str.res) ? str.res : str.res);
    }
}
