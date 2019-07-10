/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
**
*/

#include "lemi.h"

int            lock_sem(struct sembuf *sop, int semid)
{
	sop->sem_op = -1;
	if (semop(semid, sop, 1) < 0)
		return (0);
	return (1);
}

int           unlock_sem(struct sembuf *sop, int semid)
{
	sop->sem_op = 1;
	if (semop(semid, sop, 1) < 0)
		return (0);
	return (1);
}
