/*
** destroy_server.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 19:59:37 2014 Jean Fauquenot
** Last update Thu Apr 17 20:19:22 2014 Jean Fauquenot
*/

#include	"network.h"
#include	"error.h"

#include	<errno.h>
#include	<string.h>
#include	<unistd.h>

/**
** Free and close the element of t_server.
** @param server a t_server argument.
** @return The t_state state of the function.
*/
void		destroy_server(t_server *server)
{
  if (close(server->network.fd) == -1)
    merror("%s: %s", E_CLOSE, strerror(errno));
}
