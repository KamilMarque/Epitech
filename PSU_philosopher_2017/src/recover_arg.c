/*
** EPITECH PROJECT, 2018
** Philosophe
** File description:
** No file there, just an epitech header example
*/

#include "my.h"

pthread_barrier_t		barrier;

int			my_first_pars(char *str, char *str2,
				      t_args *args)
{
	if (str && strcmp("--help", str) == 0) {
		print_usage();
		return (0);
	}
	if (strcmp("-p", str) == 0 && str2) {
		args->nbr_philo = atoi(str2);
		if (args->nbr_philo < 2)
			return (-1);
	}
	else if (strcmp("-e", str) == 0 && str2) {
		args->nbr_time = atoi(str2);
		if (args->nbr_philo == 0)
			return (-1);
	}
	else {
		print_usage();
		return (-1);
	}
	return (0);
}

int 			init(int ac, char **av)
{
	t_args		args;

	srand(time(NULL));
	if (ac != 5) {
		print_usage();
		return (-1);
	}
	for (int i = 1; i < 4; i += 2) {
		if (my_first_pars(av[i], av[i + 1], &args) == -1)
			return (-1);
	}
	args.act = REST;
	for (int i = 0; i < args.nbr_philo; i++) {
		args.act = i % 3;
		if (insert_at_tail(i, args) < 0)
			return (-1);
	}
	return (0);
}

int 			join(void)
{
	t_args		*args = head;
	pthread_t  	philo[args->nbr_philo];

	if (pthread_barrier_init(&barrier, NULL, args->nbr_philo + 1) < 0) {
		perror("Error: Philo:");
		return (-1);
	}
	for (int i = 0; args && i < args->nbr_philo; i++) {
		if (pthread_create(&philo[i], NULL, philosophe, args) < 0)
			return (-1);
		args = args->next;
	}
	sleep(1);
	pthread_barrier_wait(&barrier);
	for (int i = 0; args && i < args->nbr_philo; i++) {
		if (pthread_join(philo[i], NULL) < 0)
			return (-1);
		args = args->next;
	}
	return (0);
}

int 				destroy(void)
{
	t_args 			*tmp = head;

	while (tmp != NULL) {
		if (pthread_mutex_destroy(&tmp->lock) < 0)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int				main(int ac, char **av)
{
	RCFStartup(ac, av);
	if (init(ac, av) < 0) {
		RCFCleanup();
		return (84);
	}
	if (join() < 0) {
		fprintf(stderr, "Philo: error: thread "
			"couldn't be created.\n");
		RCFCleanup();
		return (84);
	}
	if (destroy() < 0) {
		fprintf(stderr, "Philo: error: thread "
			"couldn't be destroyed.\n");
		RCFCleanup();
		return (84);
	}
	RCFCleanup();
	return (0);
}
