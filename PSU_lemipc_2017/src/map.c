/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

void		usage(void)
{
	fprintf(stderr,
	        "Usage : ./lemipc path_to_key nb_team\n\n"
	        "path_to_key\tis a valid path"
	        " that will be used by ftok\n"
	        "team_number\tis the team number"
	        " assigned to the current player\n");
}

void    	my_putchar(char a)
{
	write(1, &a, 1);
}

int		is_num(char *s)
{
	for (int i = 0; s[i]; i++) {
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (0);
}

void    	print_map(char *s)
{
	int   	i;

	i = 0;
	while (s[i])
	{
		if ((i) % 10 == 0 && i != 0)
			my_putchar('\n');
		my_putchar(s[i++]);
	}
	my_putchar('\n');
}

int 		game_done(t_id *id, t_player *player)
{
	char 	*shm;

	shm = shmat(id->shmid, NULL, 0);
	if (shm == (char *) - 1)
		err_aff("shmat");
	for (int i = 0; shm[i]; i++) {
		if (shm[i] != '0' && shm[i] != player->nb_team + 48)
			return (-1);
	}
	return (0);
}
