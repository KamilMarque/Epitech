##
## Makefile for makefile in /home/cathal_n/EPITECH_YEAR_2/unix_mem/malloc/PSU_2016_malloc
##
## Made by nicolas cathala
## Login   <cathal_n@epitech.net>
##
## Started on  Thu Feb  9 17:56:45 2017 nicolas cathala
## Last update Thu Feb  9 18:03:26 2017 nicolas cathala
##

SRC	= malloc.c \
	  free.c \
	  liste.c

NAME	= libmy_malloc.so

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -W -Wall -Wextra -Werror -c -fPIC

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -shared -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

