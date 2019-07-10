/*
** EPITECH PROJECT, 2018
** Philosophe
** File description:
** No file there, just an epitech header example
*/
#include "my.h"

void			go_think(t_args *args)
{
	pthread_mutex_trylock(&args->lock);
	lphilo_take_chopstick(&args->lock);
	lphilo_think();
	args->previous = args->act;
	args->act = THINK;
	usleep(args->tpsthink);
	pthread_mutex_unlock(&args->lock);
	lphilo_release_chopstick(&args->lock);
}

void			go_rest(t_args *args)
{
	usleep(rand() % 100);
	lphilo_sleep();
	args->previous = args->act;
	args->act = REST;
}

int			lock_prev(t_args *args)
{
	if (args->prev) {
		pthread_mutex_lock(&args->prev->lock);
		lphilo_take_chopstick(&args->prev->lock);
		return (2);
	}
	else if (!args->prev) {
		pthread_mutex_lock(&(get_last_node())->lock);
		lphilo_take_chopstick(&(get_last_node())->lock);
		return (3);
	}
	return (-1);
}

void			go_eat(t_args *args)
{
	int		left = lock_prev(args);

	if (pthread_mutex_lock(&args->lock) == 0) {
		lphilo_take_chopstick(&args->lock);
		lphilo_eat();
		usleep(args->tpseat);
		args->previous = args->act;
		args->act = EAT;
		args->nbeat += 1;
		pthread_mutex_unlock(&args->lock);
		lphilo_release_chopstick(&args->lock);
	}
	if (left == 2) {
		pthread_mutex_unlock(&args->prev->lock);
		lphilo_release_chopstick(&args->prev->lock);
	}
	else {
		pthread_mutex_unlock(&get_last_node()->lock);
		lphilo_release_chopstick(&get_last_node()->lock);
	}
}

void			*philosophe(void *arg)
{
	t_args 		*args = (t_args *)arg;

	while (args->nbeat < args->nbr_time)
	{
		if (args->act == EAT) {
			go_eat(args);
		}
		else if (args->act == THINK &&
			 args->previous != THINK) {
			go_think(args);
		}
		else if (args->previous != THINK)
			go_rest(args);
		next_state(args);
	}
	pthread_barrier_wait(&barrier);
	return (NULL);
}
