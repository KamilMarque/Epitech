##
## Makefile for  in /home/henry_g/sudoku-bi
## 
## Made by Clément Henry
## Login   <henry_g@epitech.net>
## 
## Started on  Sun Feb 28 03:40:18 2016 Clément Henry
## Last update Sun Feb 28 21:08:51 2016 Kamil Marque
##

SRC     = 	main.c \
		fill_tab.c \
		fill_tab2.c \
		check.c \
		str_to_wordtab.c \
		algo.c \
		algo2.c \
		tri.c

NAME	=	sudoki-bi

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc $(OBJ) -o $(NAME)
clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
