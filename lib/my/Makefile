##
## EPITECH PROJECT, 2017
## makefile
## File description:
## rpg lib
##

SRC	=	my_strlen.c		\
		my_getnbr.c		\
		my_putstr.c		\
		my_strcmp.c		\
		my_strcat.c		\
		my_itoa.c		\
		my_str_to_word_array.c	\
		get_next_line.c		\
		distance.c

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra --pedantic -I ../../include

all: 		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
