/*
** server.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 15:45:37 2014 Jean Fauquenot
** Last update Thu Apr 17 20:00:06 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"network.h"

t_state		server(int UNUSED(an), char **UNUSED(av))
{
  t_server	server;

  init_server(&server);
  destroy_server(&server);
  return (SUCCESS);
}
