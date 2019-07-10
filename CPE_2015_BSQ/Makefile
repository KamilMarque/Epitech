##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Sat Dec 19 12:51:37 2015 Kamil Marque
##

SRC     = 	bsq.c \
		str_to_wordtab.c \
		my_square.c

NAME	=	bsq

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
