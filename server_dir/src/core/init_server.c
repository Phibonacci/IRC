/*
** init_server.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 19:54:00 2014 Jean Fauquenot
** Last update Thu Apr 17 20:23:59 2014 Jean Fauquenot
*/

#include	"core.h"

static t_state	(*const g_init_aux[])(t_server *) =
{
  &init_protocol,
  &open_socket,
  &bind_server,
  &listen_server
};

static void	init_addr(struct sockaddr_in *addr, int port)
{
  addr->sin_family = AF_INET;
  addr->sin_port = htons(port);
  addr->sin_addr.s_addr = INADDR_ANY;
}

/**
** Initialize the network connection in the t_server structure.
** @param server a t_server argument.
** @return The t_state state of the function.
*/
t_state		init_server(t_server *server)
{
  size_t	i;

  server->network.port = 6667;
  init_addr(&(server->network.addr), server->network.port);
  i = 0;
  while (i < LEN(g_init_aux))
    {
      if (g_init_aux[i](server) == FAILURE)
	return (FAILURE);
      ++i;
    }
  return (SUCCESS);
}
