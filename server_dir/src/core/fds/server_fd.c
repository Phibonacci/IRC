/*
** server_fd.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Apr 18 13:00:53 2014 Jean Fauquenot
** Last update Fri Apr 18 18:26:28 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"

#include	<sys/select.h>

t_state		server_fd(t_select *settings,
			  t_server *server,
			  t_duser_l **clist)
{
  t_state	ret;

  if (FD_ISSET(server->network.fd, &settings->readfds))
    {
      if ((ret = add_client(server, clist)) != SUCCESS)
      	return (ret);
    }
  return (SUCCESS);
}
