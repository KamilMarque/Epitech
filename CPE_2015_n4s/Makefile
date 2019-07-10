##
## Makefile for Makefile in /home/henry_g/rendu
## 
## Made by Clément Henry
## Login   <henry_g@epitech.net>
## 
## Started on  Fri Dec  5 22:21:16 2014 Clément Henry
## Last update Sun May 29 22:46:34 2016 kamil
##

SRC=	main.c \
	my_algo.c \
	my_algo2.c \
	my_getnbr.c \
	get_next_line.c \
	str_to_wordtab.c \
	fonctions.c

NAME=	ia

OBJ=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all
