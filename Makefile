##
## Makefile for makefile in /home/paskal/rendu/System_Unix/PSU_2016_philo/
##
## Made by Paskal Arzel
## Login   <paskal.arzel@epitech.eu>
##
## Started on  Mon Mar  6 15:33:06 2017 Paskal Arzel
## Last update Tue Mar  5 13:19:45 2019 Paskal Arzel
##

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"
BLUE		=	"\033[0;34m"

DIR_INC = ./include/
DIR_INIT = ./src/init/
DIR_SRC = ./src/
DIR_ERR = ./src/error/
DIR_PRINT = ./src/print/

SRC 	=	$(DIR_SRC)main.c \
				$(DIR_SRC)sort.c \
				$(DIR_INIT)init.c \
				$(DIR_PRINT)print.c \
				$(DIR_ERR)error.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-Wextra \
		-Wall \
		-Werror \
		-O3 \
		-lm \
		-I$(DIR_INC) \
		-g

LDFLAGS +=	-L./lib

NAME	= sort

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) ./$(NAME)

re:		fclean all

.c.o:
		@gcc $(CFLAGS) $(LDFLAGS) -c $< -o $@ && \
		$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

.PHONY: all clean fclean re libmy getch $(NAME) .c.o message
