/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** 
*/

#include "lemi.h"

void		err_aff(char *s)
{
	perror(s);
	exit (EXIT_FAILURE);
}
