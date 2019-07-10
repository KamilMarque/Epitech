##
## Makefile for Makefile in /home/henry_g/rendu
## 
## Made by Clément Henry
## Login   <henry_g@epitech.net>
## 
## Started on  Fri Dec  5 22:21:16 2014 Clément Henry
## Last update Wed Jun 15 10:20:10 2016 kamil
##

SRC	=	pars.c \
		realloc.c \
		puts_errors.c \
		fonctions.c \
		str_to_wordtab.c \
		listes.c \
		my_rem_list.c \
		gestion_start.c \
		option_i.c

NAME	=	SBMLparser

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:	fclean all
