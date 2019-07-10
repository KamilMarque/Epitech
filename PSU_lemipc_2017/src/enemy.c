/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

char			check_enemy_right(t_player *player,
					  char *map, char *value)
{
	int		x = player->x;
	int		y = player->y;

	if (out_bound(x, y, RIGHT) &&
	    ENEMY(MAP_RIGHT(x, y, map), player->nb_team)) {
		*value = MAP_RIGHT(x, y, map);
		return (*value);
	}
	return ('0');
}

char			check_enemy_left(t_player *player,
					 char *map, char *value)
{
	int		x = player->x;
	int		y = player->y;

	if (out_bound(x, y, LEFT) &&
	    ENEMY(MAP_LEFT(x, y, map), player->nb_team)) {
		*value = MAP_LEFT(x, y, map);
		return (*value);
	}
	return ('0');
}

char			check_enemy_up(t_player *player,
				       char *map, char *value)
{
	int		x = player->x;
	int		y = player->y;

	if (out_bound(x, y, UP) &&
	    ENEMY(MAP_UP(x, y, map), player->nb_team)) {
		*value = MAP_UP(x, y, map);
		return (*value);
	}
	return ('0');
}

char			check_enemy_down(t_player *player,
					 char *map, char *value)
{
	int		x = player->x;
	int		y = player->y;

	if (out_bound(x, y, DOWN) &&
	    ENEMY(MAP_DOWN(x, y, map), player->nb_team)) {
		*value = MAP_DOWN(x, y, map);
		return (*value);
	}
	return ('0');
}

int			check_others(t_player *player, char *map,
				     char value, int pos)
{
	char 		val = '0';

	if (pos != RIGHT &&
	    check_enemy_right(player, map, &val) == value)
		return (1);
	if (pos != LEFT &&
	    check_enemy_left(player, map, &val) == value)
		return (1);
	if (pos != UP &&
	    check_enemy_up(player, map, &val) == value)
		return (1);
	if (pos != DOWN &&
	    check_enemy_down(player, map, &val) == value)
		return (1);
	return (check_others_diag(player, map, value, pos));
}
