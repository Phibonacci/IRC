/*
** clients_fd.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 17:03:11 2014 Jean Fauquenot
** Last update Sun Apr 27 22:40:47 2014 Jean Fauquenot
*/

#include	"core.h"

t_state		handle_fds_clients(t_select *settings,
				   t_server *server,
				   t_irc *irc)
{
  if (handle_fds_clients_write(settings, server, &irc->users, irc) == FAILURE)
    return (FAILURE);
  if (handle_fds_clients_read(settings, server, irc) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
