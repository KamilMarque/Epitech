##
## EPITECH PROJECT, 2018
## Philosophe
## File description:
## No file there, just an epitech header example
##

CFLAGS	= -W -Wall -Werror -Wextra -Iinclude/
LDFLAG	= -L./lib/ -lriceferee -lpthread

NAME	= philo

SRC	=	src/recover_arg.c \
		src/double_linked_list.c \
		src/philo.c \
		src/utils.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAG)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
