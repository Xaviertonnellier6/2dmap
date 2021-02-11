##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	2dmap.c \

OBJS = $(SRCS:.c=.o)

NAME = 2dgame

all : $(NAME)

$(NAME) :
	gcc -g -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -I include

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

x : re
	./$(NAME)