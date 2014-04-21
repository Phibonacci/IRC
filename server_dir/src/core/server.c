/*
** server.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 15:45:37 2014 Jean Fauquenot
** Last update Fri Apr 18 12:21:15 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"network.h"

/**
** The main function of the irc server.
** @param an an integrer argument.
** @param av a pointer on pointer on char.
** @return The t_state state of the function.
*/
t_state		server(int UNUSED(an), char **UNUSED(av))
{
  t_server	server;

  if (init_server(&server) == FAILURE)
    return (FAILURE);
  if (select_loop(&server) == FAILURE)
    {
      destroy_server(&server);
      return (FAILURE);
    }
  destroy_server(&server);
  return (SUCCESS);
}
