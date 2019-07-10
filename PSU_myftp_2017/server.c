/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "myftp.h"

void				final_print(char *str)
{
	printf("%s\n", str);
	exit (84);
}

struct sockaddr_in		init_sock(struct sockaddr_in s_in, t_struct ftp)
{
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(ftp.port);
	s_in.sin_addr.s_addr = INADDR_ANY;
	return (s_in);
}

void				my_server(t_struct ftp)
{
	struct protoent		*proto = getprotobyname("TCP");
	struct sockaddr_in	s_in = init_sock(s_in, ftp);
	int			fd;

	if (!proto)
		final_print("Error in function getprotobyname");
	fd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (fd == -1)
		final_print("Error with fd");
	if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		if (close(fd) == -1)
			final_print("Error in function close");
		final_print("Error in function bind");
	}
	if (listen(fd, 42) == -1) {
		if (close(fd) == -1)
			final_print("Error in function close");
		final_print("Error in function listen");
	}
	clients(ftp, proto, s_in, fd);
}
