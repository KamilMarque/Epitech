##
## Makefile for  in /home/marque_p/rendu/CPE_2015_Pushswap
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 19 14:16:06 2015 Kamil Marque
## Last update Fri Nov 27 16:37:26 2015 Kamil Marque
##

SRC     = 	my_ls.c \
		liste.c \
		trie.c \
		my_fonction.c \
		my_options.c \
		no_options.c

NAME	=	my_ls

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
