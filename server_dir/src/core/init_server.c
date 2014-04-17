/*
** init_server.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 19:54:00 2014 Jean Fauquenot
** Last update Thu Apr 17 19:56:33 2014 Jean Fauquenot
*/

#include	"core.h"

static void	init_addr(struct sockaddr_in *addr, int port)
{
  addr->sin_family = AF_INET;
  addr->sin_port = htons(port);
  addr->sin_addr.s_addr = INADDR_ANY;
}

t_state		init_server(t_server *server)
{
  server->network.port = 6667;
  init_addr(&(server->network.addr), server->network.port);
  if (init_protocol(server) == FAILURE
      || open_socket(server) == FAILURE
      || bind_server(server) == FAILURE
      || listen_server(server) == FAILURE)
    {
      return (FAILURE);
    }
  return (SUCCESS);
}
