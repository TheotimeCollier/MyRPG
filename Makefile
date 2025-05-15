##
## EPITECH PROJECT, 2023
## makefile
## File description:
## 10
##

SRC	=	$(wildcard src/*.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-Wall -Wextra -I./include/ -g

FLAGSGRAP	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

RESOURCE_URL = https://lucasrpg.aidetek.xekkcorp.eu/ressource.zip
RESOURCE_DIR = ressource
RESOURCE_ZIP = ressource.zip

all: $(NAME)

check_ressource:
	@if [ ! -d $(RESOURCE_DIR) ]; then \
		echo "Ressource directory not found. Downloading..."; \
		curl -o $(RESOURCE_ZIP) $(RESOURCE_URL); \
		unzip $(RESOURCE_ZIP) -d ./; \
		rm $(RESOURCE_ZIP); \
	else \
		echo "Ressource directory exists. Checking for updates..."; \
		curl -o $(RESOURCE_ZIP) $(RESOURCE_URL); \
		unzip -o $(RESOURCE_ZIP) -d ./; \
		rm $(RESOURCE_ZIP); \
	fi

$(NAME): $(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(OBJ) $(FLAGSGRAP) -L ./ -lmy -lm

clean:
	cd lib/my && make fclean
	rm -f $(OBJ) $(NAME) libmy.a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean check_ressource
