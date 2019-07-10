/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "myftp.h"

t_fd_msg			init_fd_msg_struct(t_fd_msg msg)
{
	msg.m_120 = "Service ready in nnn minutes.\r\n";
	msg.m_125 = "Data connection already open; transfer starting.\r\n";
	msg.m_150 = "File status okay; about to open data connection.\r\n";
	msg.m_200 = "Command okay.\r\n";
	msg.m_220 = "220 Service ready for a new user.\r\n";
	msg.m_221 = "221 Service closing control connection.\r\n";
	msg.m_230 = "230 User logged in, proceed.\r\n";
	msg.m_250 = "250 Requested file action okay, completed.\r\n";
	msg.m_331 = "331 User name okay, need password.\r\n";
	msg.m_332 = "332 Need account for login.\r\n";
	msg.m_530 = "530 Not logged in.\r\n";
	return (msg);
}

void				fd_msg(int val, int client_fd, t_struct *ftp)
{
	t_fd_msg		msg = init_fd_msg_struct(msg);

	if (val == 220)
		write(client_fd, msg.m_220, strlen(msg.m_220));
	else if (val == 221) {
		write(client_fd, msg.m_221, strlen(msg.m_221));
		exit (84);
	}
	else if (val == 250)
		write(client_fd, msg.m_250, strlen(msg.m_250));
	else if (val == 331)
		write(client_fd, msg.m_331, strlen(msg.m_331));
	else if (val == 530)
		write(client_fd, msg.m_530, strlen(msg.m_530));
}

int				command2(int client_fd, t_struct *ftp, char *str)
{
	if (strncmp(str, "NOOP", 4) == 0)
		write(client_fd, "200 NOOP ok.\r\n", 14);
	else if (strncmp(str, "HELP", 4) == 0)
		write(client_fd, "214-USER PASS CWD PWD QUIT HELP\r\n", 34);
	else if (strncmp(str, "PWD", 3) == 0)
		pwd(client_fd, ftp->path);
	else if (strncmp(str, "CWD", 3) == 0)
		my_cwd(client_fd, str, ftp);
	else
		write(client_fd, "500 Unknown command.\r\n", 22);
}

int				command(int client_fd, t_struct *ftp)
{
	char			str[100];

	if (read(client_fd, str, 100) == -1)
		final_print("Error in function read");
	if (strncmp(str, "USER", 4) == 0)
		user(client_fd, str, ftp);
	else if (strncmp(str, "PASS", 4) == 0)
		my_pass(ftp, client_fd, str);
	else if (strncmp(str, "QUIT", 4) == 0)
		return (-1);
	else if (ftp->anony != 2)
		write(client_fd, "530 Please login with USER and PASS.\r\n", 38);
	else
		command2(client_fd, ftp, str);
	memset(str, 0, strlen(str));
}

void                            clients(t_struct ftp, struct protoent *proto,
                                        struct sockaddr_in s_in, int fd)
{
	int			pid;
	int			client_fd;
	char			*client_ip;
	struct sockaddr_in	s_in_client;
	socklen_t		s_in_size = sizeof(s_in_client);

	while (42) {
		client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
		if (client_fd == -1)
			final_print("Error in function close");
		pid = fork();
		if (pid == 0) {
			client_ip = inet_ntoa(s_in_client.sin_addr);
			if (client_ip == NULL)
				final_print("Error in function inet_ntoa");
			fd_msg(220, client_fd, &ftp);
			while (42)
				if (command(client_fd, &ftp) == -1)
					fd_msg(221, client_fd, &ftp);
		}
	}
}

