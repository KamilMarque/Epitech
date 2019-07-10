##
## Makefile for  in /home/roche_h/cpp_indie_studio
##
## Made by Hugo Roche
## Login   <roche_h@epitech.net>
##
## Started on  Wed May  3 19:52:34 2017 Hugo Roche
## Last update Sun Jun 11 15:34:57 2017 nicolas cathala
##

CPPFLAGS += -W -Wall -Werror -std=c++11

NAME	= trade

SRC	= src/main.cpp \
	  src/wallet.cpp

OBJ	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
