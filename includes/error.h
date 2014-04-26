/*
** error.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 16:19:09 2014 Jean Fauquenot
** Last update Tue Apr 22 13:21:42 2014 Jean Fauquenot
*/

#ifndef ERROR_H_
# define ERROR_H_

# include		"usual.h"

# define BIN		"server"

# define USAGE		"Usage : ./" BIN

# define EHEADER	BIN ": error: "

# define E_PROTO	"Could not get protocol datas"
# define E_ARGC		"Invalid arguments"
# define E_SEND		"Could not send data to the socket"
# define E_RECV		"Client disconnection"
# define E_CLOSE	"Could not close the file"
# define E_SELECT	"Could not get the state of the file descriptors"
# define E_ACCEPT	"Could not accept the new client"
# define E_ALLOC	"Could not allocate memory"
# define E_OPEN		"Could not open the file"
# define E_WRFILE	"Could not write in the file"
# define E_SOCKET	"Could not open the socket"
# define E_BIND		"Could not bind the name to the socket"
# define E_LISTEN	"Could not listen to the socket"
# define E_NOTINLIST	"Could not find the element in the list (ignored)"
# define E_READ		"Could not read"

t_state		merror(char *, ...);

#endif /* !ERROR_H_ */
