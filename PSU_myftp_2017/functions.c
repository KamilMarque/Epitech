/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "myftp.h"

void                            pwd(int client_fd, char *path)
{
	write(client_fd, "257 ", 4);
	write(client_fd, path, strlen(path));
	write(client_fd, "\r\n", 2);
}

void				user(int client_fd, char *str, t_struct *ftp)
{
	if (strncmp(&str[5], "Anonymous", 9) == 0) {
		fd_msg(331, client_fd, ftp);
		ftp->anony = 1;
	}
	else if (strlen(str) == 6 || ftp->anony == 2) {
		fd_msg(530, client_fd, ftp);
		ftp->anony = 0;
	}
	else {
		fd_msg(331, client_fd, ftp);
		ftp->anony = 0;
	}
}

void				my_pass(t_struct *ftp, int fd, char *str)
{
	if (ftp->anony == 1) {
		write(fd, "230 User logged in, proceed.\r\n", 31);
		ftp->anony = 2;
	}
	else if (ftp->anony == -1)
		write(fd, "503 Login with USER first.\r\n", 28);
	else
		write(fd, "530 Not logged in.\r\n", 20);
}

void				my_cwd(int client_fd, char *str, t_struct *ftp)
{
	char			*nw_psswd;

	str[strlen(str) - 1] = '\0';
	nw_psswd = strdup(&str[5]);
	if (access(nw_psswd, F_OK) == -1)
		write(client_fd, "550 Failed to change directory.\r\n", 33);
	else {
		ftp->path = strdup(nw_psswd);
		write(client_fd, "250 Directory successfully changed.\r\n", 38);
	}
}
