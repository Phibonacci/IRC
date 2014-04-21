##
## Makefile for  in ./
## 
## Made by Jean Fauquenot
## Login   <fauque_j@epitech.net>
## 
## Started on  Mon Apr 21 19:48:01 2014 Jean Fauquenot
## Last update Mon Apr 21 19:48:02 2014 Jean Fauquenot
##

DEBUG		=	0

NAME		=	server

BUILD		=	build

INCLUDES	=	-I./../includes -I src/includes/

SRC		=	main.c
VPATH		=	src

SRC		+=	error.c
VPATH		+=	:src/utils

SRC		+=	server.c \
			init_server.c \
			init_server_aux.c \
			destroy_server.c \
			select_loop.c \
			set_select.c
VPATH		+=	:src/core

SRC		+=	handle_fds.c \
			server_fd.c \
			add_client.c \
			remove_client.c \
			handle_fds_clients.c \
			handle_fds_clients_read.c
VPATH		+=	:src/core/fds

OBJ		=	$(patsubst %.c,$(BUILD)/%.o,$(SRC))

CC		=	gcc

CFLAGS		=	-W -Wall -Wextra
CFLAGS		+=	-Werror
CFLAGS		+=	$(INCLUDES)
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
