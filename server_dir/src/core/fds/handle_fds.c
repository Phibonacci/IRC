/*
** handle_fds.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Apr 18 12:52:49 2014 Jean Fauquenot
** Last update Fri Apr 18 14:17:31 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"

t_state		handle_fds(t_select *settings,
			   t_server *server,
			   t_user_l *clist)
{
  server_fd(settings, server, clist);
  /* client_fd_write(); */
  /* client_fd_read(); */
  return (SUCCESS);
}
