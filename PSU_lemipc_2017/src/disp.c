/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

static void		clear_screen(void)
{
	const char	*clear;

	clear = "\e[1;1H\e[2J";
	write(1, clear, 11);
}

void    		main_disp(t_id *id)
{
	char  		*map;

	map = shmat(id->shmid, NULL, 0);
	if (map != (char *) - 1)
	{
		clear_screen();
		if (!lock_sem(&(id->sop), id->semid))
			return ;
		print_map(map);
		if (!unlock_sem(&(id->sop), id->semid))
			return ;
	}
}
