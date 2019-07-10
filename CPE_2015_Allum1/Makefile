##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Sun Feb 21 01:05:46 2016 Kamil Marque
##

SRC     = 	allum.c \
		get_next_line.c \
		my_tab.c \
		my_check.c \
		final_moov.c

NAME	=	allum1

LDFLAGS +=      -L./lib/my -lmy

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
