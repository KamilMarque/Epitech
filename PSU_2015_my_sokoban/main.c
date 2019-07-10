/*
** main.c for  in /home/marque_p/rendu/PSU_2015_my_sokoban
**
** Made by Kamil Marque
** Login   <marque_p@epitech.net>
**
** Started on  Sat Jan 16 17:59:17 2016 Kamil Marque
** Last update Sat Jan 16 20:06:23 2016 Kamil Marque
*/

#include "my.h"

int     main(int ac, char **av)
{
  int   count;
  int   fd;
  char  buf[4097];
  char  *save;

  save = NULL;
  if (ac == 1)
    return (0);
  else
    {
      if ((fd = open((av[1]), O_RDONLY)) == -1)
	return (-1);
      while ((count = read(fd, buf, 4096)) != 0)
	{
	  buf[count] = 0;
	  save = my_save(buf, save);
	  if (save[0] != '#')
	    exit (1);
	}
      my_sokoban(save);
    }
}
