##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Sat Apr  2 22:36:26 2016 kamil
##

SRC     = 	main.c \
		str_to_wordtab.c

NAME	=	109titration

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc $(OBJ) -o $(NAME)
clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
