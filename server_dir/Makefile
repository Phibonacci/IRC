##
## Makefile for  in ./
## 
## Made by Jean Fauquenot
## Login   <fauque_j@epitech.net>
## 
## Started on  Thu Apr 17 16:14:30 2014 Jean Fauquenot
## Last update Thu Apr 17 16:14:31 2014 Jean Fauquenot
##

DEBUG		=	0

NAME		=	server

BUILD		=	build

SRC		=	main.c \
			error.c \
			server.c

VPATH		=	src

OBJ		=	$(patsubst %.c,$(BUILD)/%.o,$(SRC))

CC		=	gcc

CFLAGS		=	-W -Wall -I src/includes/
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
