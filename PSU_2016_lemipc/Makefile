NAME	= lemipc

SRC	= src/main.c \
	  src/error_file.c

OBJ	= $(SRC:.c=.o)

GCC	= cc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
