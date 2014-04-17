/*
** server.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 15:45:37 2014 Jean Fauquenot
** Last update Thu Apr 17 18:18:13 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"network.h"
#include	"error.h"

#include	<errno.h>
#include	<string.h>
#include	<unistd.h>

static void	init_addr(struct sockaddr_in *addr, int port)
{
  addr->sin_family = AF_INET;
  addr->sin_port = htons(port);
  addr->sin_addr.s_addr = INADDR_ANY;
}

static t_state	init_server(t_server *server)
{
  server->network.port = 6667;
  init_addr(&(server->network.addr), server->network.port);
  if ((server->protocol = getprotobyname("TCP")) == 0)
    return (error("%s", E_PROTO));
  if ((server->network.fd = socket(AF_INET, SOCK_STREAM,
				   server->protocol->p_proto)) == -1)
    return (error("%s: %s", E_SOCKET, strerror(errno)));
  if (bind(server->network.fd,
	   (const struct sockaddr *)&server->network.addr,
           sizeof(server->network.addr)) == -1)
    {
      error("%s: %s", E_BIND, strerror(errno));
      if (close(server->network.fd) == -1)
	error("%s: %s", E_CLOSE, strerror(errno));
      return (FAILURE);
    }
  if (listen(server->network.fd, 32) == -1)
    return (FAILURE);
  return (SUCCESS);
}

static void	destroy_server(t_server *server)
{
  if (close(server->network.fd) == -1)
    error("%s: %s", E_CLOSE, strerror(errno));
}

t_state		server(int UNUSED(an), char **UNUSED(av))
{
  t_server	server;

  init_server(&server);
  destroy_server(&server);
  return (SUCCESS);
}
