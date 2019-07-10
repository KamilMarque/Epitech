##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Sun Jan 17 13:06:13 2016 Kamil Marque
##

SRC     = 	sokoban.c \
		str_to_wordtab.c \
		my_move_left.c \
		my_move_right.c \
		my_move_up.c \
		my_move_down.c \
		my_complet_move.c \
		my_complet_move2.c \
		my_check_map.c \
		main.c

NAME	=	my_sokoban

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
