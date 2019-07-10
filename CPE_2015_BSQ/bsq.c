/*
** bsq.c for  in /home/marque_p/rendu/CPE_2015_BSQ
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Wed Dec  9 15:06:07 2015 Kamil Marque
** Last update Sat Dec 19 12:47:06 2015 Kamil Marque
*/

#include "my.h"

char	*my_save(char *buf, char *save)
{
  int	cpt1;
  int	cpt2;
  char	*tmp;

  cpt1 = 0;
  cpt2 = 0;
  if (save != NULL)
    {
      if ((tmp = malloc(sizeof(char) * (my_strlen(buf)
					+ my_strlen(save) + 1))) == NULL)
	return (NULL);
      while (save[cpt1] != 0)
	tmp[cpt2++] = save[cpt1++];
      free(save);
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

void	my_aff_map(t_square *square, char **tab)
{
  int	x;
  int	y;

  y = 1;
  while (tab[y] != 0)
    {
      x = 0;
      while (tab[y][x] != 0)
	{
	  my_putchar(tab[y][x]);
	  x++;
	}
      free(tab[y]);
      my_putchar('\n');
      y++;
    }
  free(tab);
}

int		my_algo(char **tab)
{
  t_square	square;

  square.y = 1;
  square.pos_y = -1;
  square.size_square = 1;
  while (tab[square.y] != 0)
    {
      square.x = 0;
      while (tab[square.y][square.x] != 0)
	{
	  if (tab[square.y][square.x] != '.' && tab[square.y][square.x] != 'o')
	    return (0);
	  if ((my_check_square(&square, tab, square.y, square.x)) == 1)
	    {
	      square.pos_y = square.y;
	      square.pos_x = square.x;
	      square.size_square++;
	    }
	  else
	    square.x++;
	}
      square.y++;
    }
  my_no_square(&square, tab);
}

void	my_bsq(char *str)
{
  int fd;
  char *save;
  char buf[4097];
  int	count;
  char	**tab;
  struct	stat	buffer;

  save = NULL;
  stat(str, &buffer);
  if (buffer.st_size == 0)
    exit (-1);
  if ((fd = open(str, O_RDONLY)) == -1)
    return ;
  while ((count = read(fd, buf, 4096)) != 0)
    {
      if (buf[0] > 9 && buf[0] < 0)
	exit (0);
      buf[count] = 0;
      save = my_save(buf, save);
    }
  tab = str_to_wordtab(save, '\n');
  if (my_algo(tab) == 0)
    return ;
  free (save);
}

int	main(int ac, char **av)
{
  if (ac == 1)
    return (0);
  else
    my_bsq(av[1]);
}

