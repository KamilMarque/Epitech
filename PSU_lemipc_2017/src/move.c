/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

static void		move(t_player *player,
			     char *map, int pos, t_id *id)
{
	printf("Player of team n°%d is moving\n", player->nb_team);
	if (lock_sem(&(id->sop), id->semid) < 0)
		return ;
	map[10 * player->y + player->x] = '0';
	map[pos] = player->nb_team + 48;
	if (unlock_sem(&(id->sop), id->semid) < 0)
		return ;
}

static void		move_left_right(t_player *player,
					char *map, t_id *id, int nb)
{
	int		x = player->x;
	int		y = player->y;

	if (nb == RIGHT) {
		if (out_bound(x, y, nb) && MAP_RIGHT(x, y, map) == '0') {
			move(player, map, (y * 10) + x + 1, id);
			player->x += 1;
		}
	}
	else {
		if (out_bound(x, y, nb) && MAP_LEFT(x, y, map) == '0') {
			move(player, map, (y * 10) + x - 1, id);
			player->x -= 1;
		}
	}
}

static void		move_up_down(t_player *player,
				     char *map, t_id *id, int nb)
{
	int		x = player->x;
	int		y = player->y;

	if (nb == DOWN) {
		if (out_bound(x, y, nb) && MAP_DOWN(x, y, map) == '0') {
			move(player, map, (y + 1) * 10 + x, id);
			player->y += 1;
		}
	}
	else {
		if (out_bound(x, y, nb) && MAP_UP(x, y, map) == '0') {
			move(player, map, (y - 1) * 10 + x, id);
			player->y -= 1;
		}
	}
}

void			next_move(t_player *player, char *map, t_id *id)
{
	int		nb = (rand() % 4) + 10;

	if (nb == DOWN || nb == UP) {
		move_up_down(player, map, id, nb);
	}
	else if (nb == RIGHT || nb == LEFT) {
		move_left_right(player, map, id, nb);
	}
}
