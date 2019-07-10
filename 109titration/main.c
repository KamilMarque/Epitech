/*
** main.c for  in /home/marque_p/rendu/109titration
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Wed Mar 30 15:46:10 2016 kamil
** Last update Sat Apr  2 23:00:07 2016 kamil
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

int		my_check(char *str)
{
  int		i = 0;

  if (strcmp(str, "-h") == 0)
    {
      printf("USAGE\n\n");
      printf("\t./109titration file\n\n");
      printf("DESCRIPTION\n");
      printf("\tfile\ta csv file containing %cvol;ph%c lines\n", '"', '"');
      exit(0);
    }
  while (str[i] != '\0' && str[i] != '.')
    i++;
  if (strcmp(str + i, "csv") != 0)
    return (1);
  else
    return (0);
}

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
    }
  else    if ((tmp = malloc(sizeof(char) * (my_strlen(buf) + 1))) == NULL)
    return (NULL);
  cpt1 = 0;
  while (buf[cpt1] != 0)
    tmp[cpt2++] = buf[cpt1++];
  tmp[cpt2] = 0;
  return (tmp);
}

int		my_check_tab(char **tab)
{
  int		i = 0;
  int		j;
  int		cpt_p;
  int		cpt_pv;

  while (tab[i])
    {
      j = 0;
      cpt_p = 0;
      cpt_pv = 0;
      if (tab[i][0] == 0)
	exit(84);
      while (tab[i][j])
	{
	  if (tab[i][j] >= '0' && tab[i][j] <= '9')
	    j++;
	  else if (tab[i][j] == ';')
	    {
	      j++;
	      cpt_p = 0;
	      cpt_pv++;
	    }
	  else if (tab[i][j] == '.')
	    {
	      cpt_p++;
	      j++;
	    }
	  else
	    exit(84);
	  if (cpt_p > 1 || cpt_pv > 1)
	    {
	      printf("Too much ';' or '.', please check your file.csv\n");
	      exit(84);
	    }
	}
      i++;
    }
  if (i < 5)
    {
      printf("Not enought values\n");
      exit(84);
    }
}

float		**my_int_tab(char **tab)
{
  int		i = 0;
  int		j;
  int		k;
  float		**int_tab;
  char		*tmp;

  while (tab[i++]);
  if ((int_tab = malloc(sizeof(float *) * (i))) == NULL)
     return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      if ((int_tab[i] = malloc(sizeof(float) * 2)) == NULL)
         return (NULL);
      k = 0;
      j = 0;
      while (tab[i][j] != ';')
	j++;
      if ((tmp = malloc(sizeof(char) * j)) == NULL)
         return (NULL);
      tmp = strncpy(tmp, tab[i], j);
      int_tab[i][0] = atof(tmp);
      j++;
      int_tab[i][1] =  atof(&tab[i][j]);
      i++;
      j = 0;
    }
  return (int_tab);
}

float		**my_deriv(float **valid_tab)
{
  int		i = 0;

  while (valid_tab[i + 2])
    {
      if (((valid_tab[i  + 2][0] - valid_tab[i][0]) < 0.0001) && (valid_tab[i  + 2][0] - valid_tab[i][0] > -0.0001))
	{
	  printf("%s\n","Division by 0");
	  exit(84);
	}
      valid_tab[i][1] = ((valid_tab[i + 2][1] - valid_tab[i][1]) / (valid_tab[i  + 2][0] - valid_tab[i][0]));
      valid_tab[i][0] = valid_tab[i + 1][0];
      i++;
    }
  return (valid_tab);
}

void		verif_float(float valid_float)
{
  char		check[50];
  int		i = 0;
  int		j = 0;
  snprintf(check, 50, "%f", valid_float);
  while (check[i++] != '.');
  while (check[i])
    if (check[i] == '0')
      {
	i++;
	j++;
      }
    else if (check[i] != 0 && j > 4)
      {
	i = 0;
	while (check[i] != '.')
	  printf("%c", check[i++]);
	return ;
      }
  else
    {
      i = 0;
      while (check[i - 2] != '.')
	printf("%c", check[i++]);
      return ;
      }
  i = 0;
  while (check[i] != '.')
    printf("%c", check[i++]);
}

int		max_value(float **valid_tab)
{
  int		i;
  int		save;

  save = 0;
  i = 0;
  while (valid_tab[i + 2])
    {
      if (valid_tab[i][1] > valid_tab[save][1])
	{
	  save = i;
	}
      i++;
    }
  printf("\nEquivalent point at ");
  verif_float(valid_tab[save][0]);
  printf(" ml\n");
  return (save);
}

float		verif_float2(float nbr)
{
  char		check[50];
  int		i = 0;

  snprintf(check, 50, "%f", nbr);
  while (check[i] != '.')
    i++;
  if (check[i + 1] != '0')
    return (nbr);
  i = i + 3;
  while (check[i] == '5' || check[i] == '0')
    i++;
  if (check[i] <= '5')
    nbr = nbr - 0.001;
  return (nbr);
}

void		print_valid_tab(float **valid_tab, char *str, int nbr)
{
  int		i = 0;
  static	lowl = 0;

  if (lowl > 0)
    printf("\n");
  printf("%s\n",str);
  while (valid_tab[i + nbr])
    {
      printf("volume: ");
      verif_float(valid_tab[i][0]);
      printf(" ml -> ");
      valid_tab[i][1] = verif_float2(valid_tab[i][1]);
      printf("%.2f\n", valid_tab[i][1]);
      i++;
    }
  lowl++;
}

void		my_last_calc(int max, float **tab)
{
  int	i =  max - 1;
  float	k = tab[max - 2][0];
  float k2 = tab[max - 1][0];
  float k3 = tab[max - 1][0];
  float save1 = tab[max - 2][1];
  float save2 = tab[max - 1][1];
  float save3 = save2 - save1;
  int m = 0;
  float diff = (tab[max - 1][0] - tab[max - 2][0]) * 10;
  float save4 = save3 / diff;
  float save_last_pos = 100000.0;

  printf("\n%s\n", "Second derivative estimated:");
  while (k < k2)
    {
      printf("volume: ");
      verif_float(k);
      printf(" ml -> ");
      if ((tab[max - 2][1] + (save4 * m) >= 0) && (tab[max - 2][1] + (save4 * m)) < save_last_pos)
	save_last_pos = k;
      printf("%.2f\n", tab[max - 2][1] + (save4 * m));
      m++;
      k = k + 0.1;
    }
  k = tab[max][0];
  k2 = k2 + 0.1;
  m = 1;
  save1 = tab[max - 1][1];
  save2 = tab[max][1];
  save3 = save2 - save1;
  diff = (tab[max][0] - tab[max - 1][0]) * 10;
  save4 = save3 / diff;
  while (k2 <= k + 0.1)
    {
      printf("volume: ");
      verif_float(k2);
      printf(" ml -> ");
      printf("%.2f\n", tab[max - 1][1] + (save4 * m));
      if ((tab[max - 1][1] + (save4 * m) >= 0) && (tab[max - 1][1] + (save4 * m)) < save_last_pos)
	save_last_pos = k;
      m++;
      k2 = k2 + 0.1;
    }
  printf("\n%s","Equivalent point at ");
  verif_float(save_last_pos);
  printf("%s\n", " ml");
}

int		main(int ac, char **av)
{
  int		fd;
  int		count;
  char		buf[4097];
  char		*save;
  char		**tab;
  float		**valid_tab;
  int		max_val;

  if (ac == 1)
    exit(84);
  if (my_check(av[1]) == 0)
    {
      printf("%s\n","Wrong file.");
      exit(84);
    }
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (-1);
  while ((count = read(fd, buf, 4096)) != 0)
    {
      buf[count] = 0;
      save = my_save(buf, save);
    }
  if (buf[0] == 0 || (save[0] < '0' || save[0] > '9'))
    {
      printf("%s\n","Wrong file.");
      exit(84);
    }
  tab = str_to_wordtab(save, '\n');
  my_check_tab(tab);
  valid_tab = my_int_tab(tab);
  valid_tab = my_deriv(valid_tab);
  print_valid_tab(valid_tab, "Derivative:", 2);
  max_val = max_value(valid_tab);
  valid_tab == my_deriv(valid_tab);
  print_valid_tab(valid_tab, "Second derivative:", 4);
  my_last_calc(max_val, valid_tab);
}
