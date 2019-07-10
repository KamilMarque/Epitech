##
## EPITECH PROJECT, 2018
##
## File description:
##
##

SRC=	main.c \
	client.c \
	server.c \
	functions.c

NAME=	server

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	cc $(OBJ) -o $(NAME) $(LIB)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all
