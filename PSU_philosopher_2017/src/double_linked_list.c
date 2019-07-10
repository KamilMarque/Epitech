/*
** EPITECH PROJECT, 2018
** Philosophe
** File description:
** No file there, just an epitech header example
*/

#include "my.h"

t_args			*head;

void			init_new_node(t_args *newNode, t_args args, int x)
{
	newNode->id = x;
	newNode->tpseat = rand() % 50;
	newNode->tpsthink = rand() % 50;
	newNode->nbr_philo = args.nbr_philo;
	newNode->nbr_time = args.nbr_time;
	newNode->nbeat = 0;
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->act = args.act;
	newNode->previous = args.act;
}

t_args			*get_new_node(int x, t_args args)
{
	t_args 		*newNode;

	newNode = (t_args *)malloc(sizeof(*newNode));
	if (!newNode) {
		fprintf(stderr,
			"Philo: error: memory allocation.\n");
		return (NULL);
	}
	init_new_node(newNode, args, x);
	if (pthread_mutex_init(&newNode->lock, NULL) < 0) {
		fprintf(stderr,
			"Philo: error: thread initiation failed.\n");
		return (NULL);
	}
	return (newNode);
}

t_args			*get_last_node(void)
{
	t_args 		*tmp = head;

	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int 			insert_at_tail(int x, t_args args)
{
	t_args 		*temp = head;
	t_args 		*newNode = get_new_node(x, args);

	if (!newNode)
		return (-1);
	if (head == NULL) {
		head = newNode;
		return (0);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	return (0);
}

void 			print(void)
{
	t_args 		*temp = head;

	printf("List: ");
	while (temp != NULL) {
		if (pthread_barrier_init(&barrier, NULL,
					 temp->nbr_philo) < 0) {
			perror("pthread_barrier_init:");
			return ;
		}
		temp = temp->next;
	}
	printf("\n");
}
