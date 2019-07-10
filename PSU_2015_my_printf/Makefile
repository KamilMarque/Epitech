##
## Makefile for  in /home/marque_p/rendu/PSU_2015_my_printf/lib/my
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 12 18:22:50 2015 Kamil Marque
## Last update Mon Nov 16 19:28:20 2015 Kamil Marque
##

SRC     =       lib/my/my_is_prime.c \
                lib/my/my_find_prime_sup.c \
                lib/my/my_getnbr.c \
                lib/my/my_isneg.c \
                lib/my/my_power_rec.c \
                lib/my/my_putchar.c \
                lib/my/my_put_nbr.c \
                lib/my/my_putstr.c \
                lib/my/my_revstr.c \
                lib/my/my_showmen.c \
                lib/my/my_showstr.c \
                lib/my/my_square_root.c \
                lib/my/my_strcapitalize.c \
                lib/my/my_strcat.c \
                lib/my/my_strcmp.c \
                lib/my/my_strcpy.c \
                lib/my/my_str_isalpha.c \
                lib/my/my_str_islower.c \
                lib/my/my_str_isnum.c \
                lib/my/my_str_isprintable.c \
                lib/my/my_str_isupper.c \
                lib/my/my_strlcat.c \
                lib/my/my_strlen.c \
                lib/my/my_strlowcase.c \
                lib/my/my_strncat.c \
                lib/my/my_strncmp.c \
                lib/my/my_strncpy.c \
                lib/my/my_strstr.c \
                lib/my/my_strupcase.c \
                lib/my/my_swap.c \
                lib/my/my_sort_int_tab.c \
		lib/my/my_put_nbr_base.c \
		lib/my/my_printf.c \
		lib/my/my_fonction.c

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
