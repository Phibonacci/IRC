/*
** init_server_aux.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 19:55:04 2014 Jean Fauquenot
** Last update Thu Apr 17 19:58:17 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"error.h"

#include	<unistd.h>
#include	<errno.h>
#include	<string.h>

t_state		bind_server(t_server *server)
{
  if (bind(server->network.fd,
	   (const struct sockaddr *)&server->network.addr,
           sizeof(server->network.addr)) == -1)
    {
      merror("%s: %s", E_BIND, strerror(errno));
      if (close(server->network.fd) == -1)
	merror("%s: %s", E_CLOSE, strerror(errno));
      return (FAILURE);
    }
  return (SUCCESS);
}

t_state		listen_server(t_server *server)
{
  if (listen(server->network.fd, 32) == -1)
    {
      return (merror("%s: %s", E_LISTEN, strerror(errno)));
    }
  return (SUCCESS);
}

t_state		open_socket(t_server *server)
{
  if ((server->network.fd = socket(AF_INET, SOCK_STREAM,
				   server->protocol->p_proto)) == -1)
    {
      return (merror("%s: %s", E_SOCKET, strerror(errno)));
    }
  return (SUCCESS);
}

t_state		init_protocol(t_server *server)
{
  if ((server->protocol = getprotobyname("TCP")) == 0)
    {
      return (merror("%s", E_PROTO));
    }
  return (SUCCESS);
}
