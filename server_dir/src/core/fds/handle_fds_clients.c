/*
** clients_fd.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 17:03:11 2014 Jean Fauquenot
** Last update Tue Apr 22 02:10:01 2014 Jean Fauquenot
*/

#include	"core.h"

t_state		handle_fds_clients(t_select *settings,
				   t_server *server,
				   t_duser_l **clist)
{
  if (handle_fds_clients_write(settings, server, clist) == FAILURE)
    return (FAILURE);
  if (handle_fds_clients_read(settings, server, clist) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
