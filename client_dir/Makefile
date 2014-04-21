##
## Makefile for  in /home/phibonacci/project/unix/my_irc/rendu
## 
## Made by Jean Fauquenot
## Login   <fauque_j@epitech.net>
## 
## Started on  Tue Apr 15 15:57:34 2014 Jean Fauquenot
## Last update Mon Apr 21 14:49:18 2014 Gabriel Poulet de Grimouard
##

DEBUG		=	0

NAME		=	client

BUILD		=	build

SRC		=	main.c 		\
			parser.c 	\
			user.c 		\
			user_command.c 	\
			error.c		\
			user_cmd.c

VPATH		=	src

OBJ		=	$(patsubst %.c,$(BUILD)/%.o,$(SRC))

CC		=	gcc

CFLAGS		=	-W -Wall -I src/includes/ -I ../includes
ifeq ($(DEBUG), 1)
 CFLAGS		+=	-ggdb3 -D DEBUG
endif

RM		=	rm -f

all		:	$(BUILD) $(NAME)

$(BUILD)	:
		mkdir -p $(BUILD)

$(NAME)		:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

$(BUILD)/%.o	:	%.c
		$(CC) $(CFLAGS) -c -o $@ $<

clean		:
ifeq ($(wildcard $(BUILD)), $(BUILD))
		$(RM) $(OBJ)
		-rmdir $(BUILD)
endif


fclean		:	clean
		$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
