##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Sat Feb 13 17:47:20 2016 Kamil Marque
##

SRC     = 	server/serveur.c

SRC2	=	client/client.c

NAME	=	server/server

NAME2	=	client/client

OBJ	=	$(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJ)
		cc $(OBJ) -o $(NAME)

$(NAME2):	$(OBJ2)
		cc $(OBJ2) -o $(NAME2)

clean:
		rm -rf $(OBJ) $(OBJ2)

fclean:		clean
		rm -rf $(NAME) $(NAME2)

re:		fclean all
