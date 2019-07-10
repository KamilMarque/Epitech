##
## Makefile for  in /home/marque_p/rendu/PSU_2015_my_printf/lib/my
##
## Made by Kamil Marque
## Login   <marque_p@epitech.net>
##
## Started on  Thu Nov 12 18:22:50 2015 Kamil Marque
## Last update Wed Feb 24 06:02:00 2016 Kamil Marque
##

SRC     =       my_is_prime.c \
                my_find_prime_sup.c \
                my_getnbr.c \
                my_isneg.c \
                my_power_rec.c \
                my_putchar.c \
                my_put_nbr.c \
                my_putstr.c \
                my_revstr.c \
                my_showmen.c \
                my_showstr.c \
                my_square_root.c \
                my_strcapitalize.c \
                my_strcat.c \
                my_strcmp.c \
                my_strcpy.c \
                my_str_isalpha.c \
                my_str_islower.c \
                my_str_isnum.c \
                my_str_isprintable.c \
                my_str_isupper.c \
                my_strlcat.c \
                my_strlen.c \
                my_strlowcase.c \
                my_strncat.c \
                my_strncmp.c \
                my_strncpy.c \
                my_strstr.c \
                my_strupcase.c \
                my_swap.c \
                my_sort_int_tab.c \
		my_put_nbr_base.c \
		my_printf.c \
		my_fonction.c \
		my_strdup.c

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
