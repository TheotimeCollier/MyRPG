##
## EPITECH PROJECT, 2023
## makefile
## File description:
## 10
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	+=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
