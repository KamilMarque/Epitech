##
## EPITECH PROJECT, 2018
## Lemipc
## File description:
##
##

CC	= gcc

RM	= rm -rf

NAME	= lemipc

CFLAGS	= -Wall -Werror -Wextra -Iinclude/

SRCS	= 	src/main.c\
		src/disp.c\
		src/err.c\
		src/init.c\
		src/map.c\
		src/sem_utility.c\
		src/sig.c\
		src/game_util.c\
		src/move.c\
		src/msg.c\
		src/enemy.c\
		src/enemy_diag.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
