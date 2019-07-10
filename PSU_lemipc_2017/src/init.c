/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

static void		add_player(int shmid, t_player *player, char **av)
{
	int		nb;
	char		*shm;

	nb = 0;
	shm = shmat(shmid, NULL, 0);
	if (shm == (char *) - 1)
		err_aff("shmat");
	nb = rand() % 100;
	while ((shm)[nb] != '0')
		nb = rand() % 100;
	player->nb_team = atoi(av[2]);
	(shm)[nb] = player->nb_team + '0';
	player->x = nb % 10;
	player->y = nb / 10;
	printf("New player in team:%d\n", player->nb_team);
}

static void		init_msg(t_id *id)
{
	id->msgid = msgget(key_g, 0666);
	if (id->msgid == -1)
	{
		id->msgid = msgget(key_g, IPC_CREAT | 0666);
		if (id->msgid == -1)
			err_aff("msgget");
	}
}

static void		init_sharemem(t_player *player, t_id *id)
{
	char		*shm;

	shm = NULL;
	id->shmid = shmget(key_g, MAP_SIZE, 0666);
	if (id->shmid == -1 || player->main == 1)
	{
		id->shmid = shmget(key_g, MAP_SIZE, IPC_CREAT | 0666);
		if (id->shmid == -1)
			err_aff("shmget");
		shm = shmat(id->shmid, NULL, 0);
		if (shm == (char*) - 1)
			err_aff("shmat");
		memset(shm, '0', MAP_SIZE);
	}
}

static void		init_sem(t_player *player, t_id *id)
{
	id->semid = semget(key_g, 1, 0666);
	if (id->semid == -1)
	{
		printf("Main player created\n");
		player->main = 1;
		id->semid = semget(key_g, 1, IPC_CREAT | 0666);
		if (id->semid == -1)
			err_aff("semget");
	}
	if (semctl(id->semid, 0, SETVAL, 1) == -1)
		err_aff("semctl");
	id->sop.sem_num = 0;
	id->sop.sem_op = -1;
	id->sop.sem_flg = 0;
}

void			init(char **av, t_player *player)
{
	init_sigcatch();
	key_g = ftok(av[1], PID);
	if (key_g == -1)
		err_aff("ftok");
	if (is_num(av[2])) {
		usage();
		exit(84);
	}
	init_sem(player, &t_id_g);
	init_msg(&t_id_g);
	init_sharemem(player, &t_id_g);
	if (!lock_sem(&(t_id_g.sop), t_id_g.semid))
		return ;
	add_player(t_id_g.shmid, player, av);
	unlock_sem(&(t_id_g.sop), t_id_g.semid);
}
