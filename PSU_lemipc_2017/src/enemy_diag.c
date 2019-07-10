/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

char		check_enemy_down_left(t_player *player,
				      char *map, char *value)
{
	int	x = player->x;
	int	y = player->y;

	if (out_bound_diag(x, y, DOWN_LEFT) &&
	    ENEMY(MAP_DOWN_LEFT(x, y, map),
		  player->nb_team)) {
		*value = MAP_DOWN_LEFT(x, y, map);
		return (*value);
	}
	return ('0');
}

char		check_enemy_up_left(t_player *player,
				    char *map, char *value)
{
	int	x = player->x;
	int	y = player->y;

	if (out_bound_diag(x, y, UP_LEFT) &&
	    ENEMY(MAP_UP_LEFT(x, y, map),
		  player->nb_team)) {
		*value = MAP_UP_LEFT(x, y, map);
		return (*value);
	}
	return ('0');
}

char		check_enemy_up_right(t_player *player,
				     char *map, char *value)
{
	int	x = player->x;
	int	y = player->y;

	if (out_bound_diag(x, y, UP_RIGHT) &&
	    ENEMY(MAP_UP_RIGHT(x, y, map),
		  player->nb_team)) {
		*value = MAP_UP_RIGHT(x, y, map);
		return (*value);
	}
	return ('0');
}

char		check_enemy_down_right(t_player *player,
				       char *map, char *value)
{
	int	x = player->x;
	int	y = player->y;

	if (out_bound_diag(x, y, DOWN_RIGHT) &&
	    ENEMY(MAP_DOWN_RIGHT(x, y, map),
		  player->nb_team)) {
		*value = MAP_DOWN_RIGHT(x, y, map);
		return (*value);
	}
	return ('0');
}

int		check_others_diag(t_player *player,
				  char *map, char value,
				  int pos)
{
	char 	val = '0';

	if (pos != UP_RIGHT &&
	    check_enemy_up_right(player, map, &val)
	    == value)
		return (1);
	if (pos != UP_LEFT &&
	    check_enemy_up_left(player, map, &val)
	    == value)
		return (1);
	if (pos != DOWN_RIGHT &&
	    check_enemy_down_right(player, map, &val)
	    == value)
		return (1);
	if (pos != DOWN_LEFT &&
	    check_enemy_down_left(player, map, &val)
	    == value)
		return (1);
	return (0);
}
