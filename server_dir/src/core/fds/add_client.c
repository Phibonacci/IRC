/*
** add_client.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Apr 18 18:26:35 2014 Jean Fauquenot
** Last update Sat Apr 19 19:51:10 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"

#include	<sys/socket.h>
#include	<stdlib.h>
#include	<arpa/inet.h>
#include	<string.h>
#include	<errno.h>
#include	<error.h>

static t_state	init_client_data_network(t_server *server, t_network *network)
{
  network->slen = sizeof(network->addr);
  if ((network->fd = accept(server->network.fd,
			    (struct sockaddr *)&network->addr,
			    &network->slen)) == -1)
    {
      merror("%s: %s", E_ACCEPT, strerror(errno));
      return (FAILURE_L1);
    }
  network->ip = inet_ntoa(network->addr.sin_addr);
  return (SUCCESS);
}

static t_state	init_client_data(t_server *server, t_duser *user)
{
  t_state	ret;

  memset(user, 0, sizeof(*user));
  if ((ret = init_client_data_network(server, &user->network)) != SUCCESS)
    return (ret);
  return (SUCCESS);
}

static t_state	set_client(t_server *server,
			   t_duser_l **new_elem)
{
  t_duser_l	*new;
  t_state	ret;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FAILURE);
  new->next = NULL;
  if ((ret = init_client_data(server, &new->data)) == SUCCESS)
    {
      free(new);
      return (ret);
    }
  *new_elem = new;
  return (SUCCESS);
}

t_state		add_client(t_server *server, t_duser_l **clist)
{
  t_duser_l	*new;
  t_state	ret;
  t_duser_l	*it;

  if ((ret = set_client(server, &new)) != SUCCESS)
    return (ret);
  it = *clist;
  while (it && it->next)
    it = it->next;
  if (!it)
    *clist = it;
  else
    it->next = new;
  return (SUCCESS);
}
