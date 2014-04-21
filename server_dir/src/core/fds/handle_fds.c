/*
** handle_fds.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Apr 18 12:52:49 2014 Jean Fauquenot
** Last update Mon Apr 21 18:59:05 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"

t_state		handle_fds(t_select *settings,
			   t_server *server,
			   t_user_l **clist)
{
  t_state	ret;

  if ((ret = server_fd(settings, server, clist)) == FAILURE)
    return (FAILURE);
  if ((ret = handle_fds_clients(settings, server, clist)) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
