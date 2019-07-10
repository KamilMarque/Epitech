##
## EPITECH PROJECT, 2018
##
## File description:
##
##

CXXFLAGS += -W -Wall -Werror -Wextra -std=c++14 -g3

NAME    = autoCompletion

SRC             = 	main.cpp \
			prints.cpp \
			addrs.cpp \
			pars.cpp \
			check_functions.cpp \
			getters.cpp \
			confirmedAddrs.cpp \
			ValidAddrs.cpp \
			prints2.cpp \
			sort.cpp \
			city.cpp \
			street.cpp

OBJ             = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CXXFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
