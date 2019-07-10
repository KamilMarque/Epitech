/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef _MYFTP_H_
#define _MYFTP_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_struct
{
	int	port;
	int	log;
	char	*path;
	int	anony;
}		t_struct;

typedef struct	s_fd_msg
{
	char	*m_120;
	char	*m_125;
	char	*m_150;
	char	*m_200;
	char	*m_220;
	char	*m_221;
	char	*m_230;
	char	*m_250;
	char	*m_331;
	char	*m_332;
	char	*m_530;
}		t_fd_msg;

int			usage();
void			final_print(char *str);
void			my_server(t_struct ftp);
void			fd_msg(int val, int client_fd, t_struct *ftp);
void			pwd(int client_fd, char *path);
void			user(int client_fd, char *str, t_struct *ftp);
void			my_cwd(int client_fd, char *str, t_struct *ftp);
void			my_pass(t_struct *ftp, int fd, char *str);
void			clients(t_struct ftp, struct protoent *proto,
				struct sockaddr_in s_in, int fd);
int			command(int client_fd, t_struct *ftp);
t_fd_msg		init_fd_msg_struct(t_fd_msg msg);
struct sockaddr_in	init_sock(struct sockaddr_in s_in, t_struct ftp);

#endif /* _MYFTP_H_ */
