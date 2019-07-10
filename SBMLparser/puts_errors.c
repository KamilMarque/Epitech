/*
** puts_errors.c for  in /home/marque_p/rendu/SBMLparser
** 
** Made by kamil
** Login   <marque_p@epitech.net>
** 
** Started on  Mon Jun 13 10:35:27 2016 kamil
** Last update Wed Jun 15 09:28:16 2016 kamil
*/

#include "my.h"

void		my_help()
{
  my_putstr("USAGE\n\t./SBMLparser SBMLle [-i ID [-e]] [-json]\n\n");
  my_putstr("DESCRIPTION\n\tSBMLfile SBML file\n");
  my_putstr("\t-i ID\t id of the compartment, reaction or");
  my_putstr(" product to be extracted (ignored if uncorrect)\n");
  my_putstr("\t-e   \t print the equation if a reaction");
  my_putstr("ID is given as argument (ignored otherwise)\n");
  my_putstr("\t-json \t transform the le into a JSON file\n");
}

void            my_tab_swap(char **tab, int j)
{
  char          *tmp;

  tmp = tab[j];
  tab[j] = tab[j + 1];
  tab[j + 1] = tmp;
}
