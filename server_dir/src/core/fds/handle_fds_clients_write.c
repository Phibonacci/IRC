/*
** handle_fds_clients_write.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 02:11:24 2014 Jean Fauquenot
** Last update Sun Apr 27 22:40:33 2014 Jean Fauquenot
*/

#include	"core.h"

#include	<sys/select.h>

t_state		handle_fds_clients_write(t_select *settings,
					 t_server *server,
					 t_duser_l **clist,
					 t_irc *irc)
{
  t_duser_l	*it;
  t_state	ret;

  (void)server;
  it = *clist;
  while (it)
    {
      if (FD_ISSET(it->data.network.fd, &settings->writefds))
	{
	  ret = handle_fd_client_write(&it->data);
	  if (ret == FAILURE)
	    return (FAILURE);
	  else if (ret == FAILURE_L1)
	    remove_client(irc, clist, it);
	}
      it = it->next;
    }
  return (SUCCESS);
}
