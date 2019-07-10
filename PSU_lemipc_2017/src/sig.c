/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

void            handler(int nb)
{
	(void)nb;
	printf("Player of team n°%d leave the game.\n",
	       t_player_g.nb_team);
	clean_player(t_player_g, t_id_g);
	send_player_died(&t_id_g);
	if (game_done(&t_id_g, &t_player_g) == 0) {
		shmctl(t_id_g.shmid, IPC_RMID, NULL);
		semctl(t_id_g.semid, 1, IPC_RMID);
		msgctl(t_id_g.msgid, IPC_RMID, NULL);
	}
	exit (EXIT_SUCCESS);
}

void		init_sigcatch(void)
{
	signal(SIGINT, handler);
}

