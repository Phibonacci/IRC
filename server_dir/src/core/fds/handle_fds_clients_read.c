/*
** client_fd_read.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 17:37:20 2014 Jean Fauquenot
** Last update Thu Apr 24 11:57:37 2014 Jean Fauquenot
*/

#include	"core.h"

#include	<sys/select.h>

t_state		handle_fds_clients_read(t_select *settings,
					t_server *UNUSED(server),
					t_duser_l **clist)
{
  t_duser_l	*it;
  t_state	ret;
  t_duser_l	*to_free;
  t_bool	incr;

  it = *clist;
  while (it)
    {
      incr = TRUE;
      if (FD_ISSET(it->data.network.fd, &settings->readfds))
	{
	  if ((ret = handle_fd_client_read(&it->data)) == FAILURE)
	    return (FAILURE);
	  else if (ret == FAILURE_L1)
	    {
	      incr = FALSE;
	      to_free = it;
	      it = it->next;
	      remove_client(clist, to_free);
	    }
	}
      if (incr)
	it = it->next;
    }
  return (SUCCESS);
}
