##
## Makefile for 7 in /home/phibonacci/project/unix/my_ftp/rendu
## 
## Made by Jean Fauquenot
## Login   <fauque_j@epitech.net>
## 
## Started on  Mon Apr  7 21:16:23 2014 Jean Fauquenot
## Last update Thu Apr 17 19:19:11 2014 Jean Fauquenot
##

CLIENT_DIR	=	client_dir

SERVER_DIR	=	server_dir

CLIENT_BIN	=	$(CLIENT_DIR)/client

SERVER_BIN	=	$(SERVER_DIR)/server

MAKE_CLIENT	=	make -C $(CLIENT_DIR)

MAKE_SERVER	=	make -C $(SERVER_DIR)

RM		=	rm -f

all		:	client server

client		:
		$(MAKE_CLIENT)
		cp $(CLIENT_BIN) .

server		:
		$(MAKE_SERVER)
		cp $(SERVER_BIN) .
		cp $(SERVER_BIN) serveur

clean		:
		$(MAKE_CLIENT) clean
		$(MAKE_SERVER) clean

fclean		:	clean
		$(MAKE_CLIENT) fclean
		$(MAKE_SERVER) fclean
		$(RM) client
		$(RM) serveur

re		:	fclean all

.PHONY		:	all clean fclean re
