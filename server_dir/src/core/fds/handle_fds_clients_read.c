/*
** client_fd_read.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 17:37:20 2014 Jean Fauquenot
** Last update Sun Apr 27 22:38:32 2014 Jean Fauquenot
*/

#include	"core.h"

#include	<sys/select.h>

static t_state	handle_fds_clients_read_aux(t_duser_l **it,
					    t_bool *incr,
					    t_irc *irc)
{
  t_state	ret;
  t_duser_l	*to_free;

  if ((ret = handle_fd_client_read(irc, &(*it)->data)) == FAILURE)
    return (FAILURE);
  else if (ret == FAILURE_L1)
    {
      *incr = FALSE;
      to_free = (*it);
      (*it) = (*it)->next;
      remove_client(irc, &irc->users, to_free);
    }
  return (SUCCESS);
}

t_state		handle_fds_clients_read(t_select *settings,
					t_server *UNUSED(server),
					t_irc *irc)
{
  t_duser_l	*it;
  t_state	ret;
  t_bool	incr;

  it = irc->users;
  while (it)
    {
      incr = TRUE;
      if (FD_ISSET(it->data.network.fd, &settings->readfds))
	{
	  if ((ret = handle_fds_clients_read_aux(&it, &incr, irc)) != SUCCESS)
	    return (ret);
	}
      if (incr)
	it = it->next;
    }
  return (SUCCESS);
}
