##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Wed Feb 24 19:25:17 2016 Kamil Marque
##

SRC     = 	my_select.c \
		liste.c \
		my_moov_up.c \
		my_moov_down.c \
		my_moov_left.c \
		my_moov_left2.c \
		my_space.c \
		my_calc.c

NAME	=	my_select

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
