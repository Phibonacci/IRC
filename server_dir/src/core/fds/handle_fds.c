/*
** handle_fds.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Apr 18 12:52:49 2014 Jean Fauquenot
** Last update Fri Apr 18 18:19:21 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"

t_state		handle_fds(t_select *settings,
			   t_server *server,
			   t_user_l **clist)
{
  t_state	ret;

  if ((ret = server_fd(settings, server, clist)) != SUCCESS)
    return (ret);
  /* client_fd_write(); */
  /* client_fd_read(); */
  return (SUCCESS);
}
