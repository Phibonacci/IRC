/*
** clients_fd.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 17:03:11 2014 Jean Fauquenot
** Last update Mon Apr 21 19:05:10 2014 Jean Fauquenot
*/

#include	"core.h"

t_state		handle_fds_clients(t_select *settings,
				   t_server *server,
				   t_user_l **clist)
{
  /* handle_clients_fds_write(settings, server, clist); */
  if (handle_fds_clients_read(settings, server, clist) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
