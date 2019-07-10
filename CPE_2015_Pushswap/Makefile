##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Sun Nov 22 18:57:43 2015 Kamil Marque
##

SRC     = 	pushswap.c \
		liste.c \
		trie.c

NAME	=	push_swap

LDFLAGS +=      -L./lib/my -lmy


OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		cc $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
