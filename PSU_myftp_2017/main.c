/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "myftp.h"

int			usage()
{
	printf("USAGE: ./server port path\n");
	printf("\tport is the port number on which the server socket listens\n");
	printf("\tpath is the path to the home directory for the Anonymous user\n");
	return (0);
}

int			main(int ac, char **av)
{
	t_struct	ftp;

	if (ac != 3)
		return (usage());
	if (access(av[2], F_OK) == -1)
	{
		printf("Error : bad path\n");
		return (-84);
	}
	ftp.log = 0;
	ftp.port = atoi(av[1]);
	ftp.anony = -1;
	ftp.path = strdup(av[2]);
	if (ftp.path == NULL)
	    return (usage());
	my_server(ftp);
		return (0);
}
