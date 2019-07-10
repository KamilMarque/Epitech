##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Sun Apr  3 19:24:40 2016 kamil
##

SRC     = 	main.c \
		get_next_line.c \
		str_to_wordtab2.c \
		my_calc.c \
		my_env.c \
		my_env2.c \
		my_check.c \
		my_path.c \
		my_fonction.c

NAME	=	mysh

LDFLAGS +=      -L./lib/my -lmy -lncurses

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		cc $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
		rm -rf $(OBJ)
		make clean -C lib/my/

fclean:		clean
		rm -rf $(NAME)
		make fclean -C lib/my/

re:		fclean all
