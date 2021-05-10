CPP		= g++

CPPFLAGS	= -w -Wall -Werror -Wextra -g

SRC		= main.cpp	\
		  algo.cpp

OBJ		= $(SRC:.cpp=.o)

NAME		= test

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CPP) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)
		$(RM) *~

re:
		fclean all
