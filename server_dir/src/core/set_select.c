/*
** set_select.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 20:45:44 2014 Jean Fauquenot
** Last update Thu Apr 17 21:46:43 2014 Jean Fauquenot
*/

#include	"user.h"
#include	"core.h"
#include	"select_aux.h"

#include	<stddef.h>

static int	get_ndfs(t_server *server, t_duser_l *clist)
{
  int		nfds;

  nfds = server->network.fd;
  while (clist != NULL)
    {
      if (clist->data.network.fd > nfds)
	nfds = clist->data.network.fd;
      clist = clist->next;
    }
  return (nfds);
}

void		set_select(t_select *settings, t_server *server, t_duser_l *clist)
{
  settings->ndfs = get_ndfs(server, clist);
  FD_ZERO(&settings->readfds);
  FD_ZERO(&settings->writefds);
  FD_SET(server->network.fd, &settings->readfds);
  while (clist != NULL)
    {
      FD_SET(clist->data.network.fd, &settings->readfds);
      FD_SET(clist->data.network.fd, &settings->writefds);
      clist = clist->next;
    }
}
