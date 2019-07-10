/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

key_t			key_g = 0;
t_player		t_player_g;
t_id			t_id_g;

static int		game_continue(t_player *player, t_id *id)
{
	if (read_player_died(id) == 1) {
		if (game_done(id, player) == 0) {
			send_player_died(id);
			printf("Team n°%d wins !\n", player->nb_team);
			return (1);
		}
	}
	return (0);
}

static int		game_body(t_player *player,
				  t_id *id, char *map)

{
	if (game_loose(player, map) == 1) {
		printf("Player of team n°%d died\n",
		       player->nb_team);
		clean_player(*player, *id);
		send_player_died(id);
		return (1);
	}
	if (game_continue(player, id) > 0)
		return (2);
	next_move(player, map, id);
	if (player->main == 1) {
		main_disp(id);
	}
	sleep(1);
	return (0);
}

static int		game_loop(t_player *player, t_id *id)
{
	int 		action = 0;
	char		*map;

	while (1)
	{
		map = shmat(id->shmid, NULL, 0);
		if (map == (char*) - 1)
			err_aff("semget");
		action = game_body(player, id, map);
		if (action == 1)
			return (0);
		else if (action == 2)
			return (1);
	}
	return (0);
}

static void		rest(t_player *player, t_id *id)
{
	while (1)
	{
		if (player->main == 1)
			main_disp(id);
		sleep(1);
	}
}

int			main(int ac, char **av)
{
	if (ac < 3)
	{
		usage();
		return (84);
	}
	srand(time(NULL));
	init(av, &t_player_g);
	if (game_loop(&t_player_g, &t_id_g) == 2) {
		printf("Team n°%d wins !\n", t_player_g.nb_team);
	}
	rest(&t_player_g, &t_id_g);
	return (0);
}
