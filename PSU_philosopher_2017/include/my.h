/*
** EPITECH PROJECT, 2018
** Philosophe
** File description:
** No file there, just an epitech header example
*/
#ifndef _MY_H_
# define _MY_H_
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include "extern.h"

typedef enum
{
	REST,
	THINK,
	EAT
} status;

typedef struct				s_args
{
	int				id;
	int				nbeat;
	int				nbr_philo;
	int				nbr_time;
	int				tpseat;
	int				tpsthink;
	struct s_args			*next;
	struct s_args			*prev;
	pthread_mutex_t			lock;
	status				act;
	status				previous;
	pthread_barrier_t		barrier;
}					t_args;

extern	t_args				*head;
extern pthread_barrier_t		barrier;

int 					insert_at_tail(int, t_args);
void					print_usage(void);
void					next_state(t_args*);
void					*philosophe(void*);
t_args					*get_last_node(void);
void					print(void);
#endif
