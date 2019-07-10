/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#ifndef LEMI_H_
# define LEMI_H_

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <time.h>

# define MAP_SIZE 100
# define PID 4344
# define ENEMY(_x, _y) (_x != '0' && _x != _y + 48 ? 1 : 0)
# define MAP_RIGHT(x, y, map) (map[(y * 10) + x + 1])
# define MAP_LEFT(x, y, map) (map[(y * 10) + x - 1])
# define MAP_UP(x, y, map) (map[(y - 1) * 10 + x])
# define MAP_DOWN(x, y, map) (map[(y + 1) * 10 + x])
# define MAP_UP_RIGHT(x, y, map) (map[(y - 1) * 10 + x + 1])
# define MAP_UP_LEFT(x, y, map) (map[(y - 1) * 10 + x - 1])
# define MAP_DOWN_RIGHT(x, y, map) (map[(y + 1) * 10 + x + 1])
# define MAP_DOWN_LEFT(x, y, map) (map[(y + 1) * 10 + x - 1])
# define RIGHT 10
# define LEFT 11
# define UP 12
# define DOWN 13
# define UP_RIGHT 14
# define UP_LEFT 15
# define DOWN_RIGHT 16
# define DOWN_LEFT 17
# define PLAYER_DIED 4

typedef struct		s_player
{
	int		x;
	int		y;
	int		nb_team;
	int		main;
}		   	t_player;

typedef struct		s_id
{
	int		semid;
	int		shmid;
	int		msgid;
	int		pid;
	struct sembuf	sop;
}			t_id;

typedef	struct 		s_msg
{
	long		mtype;
	char		mtext[2];
}			t_msg;

extern	key_t		key_g;
extern	t_player	t_player_g;
extern	t_id		t_id_g;

void	err_aff(char *);
int	unlock_sem(struct sembuf *, int);
int	lock_sem(struct sembuf *, int);
void	print_map(char *);
void	main_disp(t_id*);
void	init_sigcatch(void);
void	init(char **, t_player *);
void	usage(void);
void	clean_player(t_player, t_id);
void	next_move(t_player *, char *, t_id *);
int	is_num(char *);
int	game_done(t_id *, t_player *);
int	game_loose(t_player *, char *);
int	out_bound(int, int, int);
void	send_player_died(t_id *);
int	read_player_died(t_id *);
char	check_enemy_right(t_player *, char *, char *);
char	check_enemy_left(t_player *, char *, char *);
char	check_enemy_up(t_player *, char *, char *);
char	check_enemy_down(t_player *, char *, char *);
int	check_others(t_player *, char *, char, int);
int	check_others_diag(t_player*, char *, char, int);
int	out_bound_diag(int, int, int);
#endif
