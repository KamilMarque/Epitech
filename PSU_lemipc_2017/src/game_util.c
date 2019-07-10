/*
** EPITECH PROJECT, 2018
** lemic
** File description:
**
*/

#include "lemi.h"

int			game_loose(t_player *player, char *map)
{
	char 		value = '0';

	(void)value;
	if (check_enemy_right(player, map, &value) != '0')
		if (check_others(player, map, value, RIGHT))
			return (1);
	if (check_enemy_left(player, map, &value) != '0')
		if (check_others(player, map, value, LEFT))
			return (1);
	if (check_enemy_down(player, map, &value) != '0')
		if (check_others(player, map, value, DOWN))
			return (1);
	if (check_enemy_up(player, map, &value) != '0')
		if (check_others(player, map, value, UP))
			return (1);
	return (0);
}

static	int		retry_lock(t_id id)
{
	if (unlock_sem(&(id.sop), id.semid) > 0)
	{
		if (lock_sem(&(id.sop), id.semid) < 0)
			return (-1);
		return (0);
	}
	return (-1);
}

void			clean_player(t_player player, t_id id)
{
	char		*map;

	id.shmid = shmget(key_g, MAP_SIZE, 0666);
	if (id.shmid != -1) {
		map = shmat(id.shmid, NULL, 0);
		if (map == (char *) - 1)
			err_aff("shmat");
		if (lock_sem(&(id.sop), id.semid) < 0)
			if (retry_lock(id) < 0)
				return ;
		map[player.y * 10 + player.x] = '0';
		if (unlock_sem(&(id.sop), id.semid) < 0)
			return ;
	}
}

int			out_bound(int x, int y, int nb)
{
	if (nb == DOWN && (y + 1) * 10 + x > MAP_SIZE)
		return (0);
	if (nb == UP && y - 1 < 0)
		return (0);
	if (nb == RIGHT && x + 1 > 9)
		return (0);
	if (nb == LEFT && x - 1 < 0)
		return (0);
	return (1);
}

int			out_bound_diag(int x, int y, int nb)
{
	if (nb == DOWN_RIGHT &&
	        x + 1 < 10 && (y + 1) * 10 + x + 1 < MAP_SIZE)
		return (1);
	if (nb == DOWN_LEFT &&
	        x - 1 >= 0 && (y + 1) * 10 + x - 1 < MAP_SIZE)
		return (1);
	if (nb == UP_RIGHT && x + 1 < 9 && y - 1 >= 0)
		return (1);
	if (nb == UP_LEFT && x - 1 >= 0 && y - 1 >= 0)
		return (1);
	return (0);
}
