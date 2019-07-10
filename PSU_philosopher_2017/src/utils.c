/*
** EPITECH PROJECT, 2018
** Philosophe
** File description:
** No file there, just an epitech header example
*/

#include "my.h"

void		print_usage(void)
{
	fprintf(stdout, "USAGE\n\t./philo -p nbr_p -e nbr_e\n"
	        "DESCRIPTION\n\t-p nbr_p\tnumber of philosophers\n\t"
	        "-e nbr_e\tmaximum number times a philosopher eats"
	        "before exiting the program\n");
}

void		next_state(t_args *args)
{
	args->previous = args->act;
	if (args->nbr_philo == 2)
		args->act = (args->act + 1) % 2;
	else
		args->act = (args->act + 1) % 3;
}