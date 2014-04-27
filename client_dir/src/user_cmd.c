/*
** user_cmd.c for user in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Sat Apr 19 16:41:29 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 22:09:05 2014 Gabriel Poulet de Grimouard
*/

#define _XOPEN_SOURCE 700

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "client.h"
#include "user.h"
#include "usual.h"
#include "error.h"

int			user_connect_to_srv(t_network *net,
					    int port, in_addr_t ip)
{
  struct protoent	*pe;
  struct sockaddr_in	*addr;

  addr = &net->addr;
  pe = getprotobyname("TCP");
  if ((net->fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (merror("%s: %s", "socket failed", strerror(errno)));
  addr->sin_family = AF_INET;
  addr->sin_port = htons(port);
  addr->sin_addr.s_addr = ip;
  if (connect(net->fd, (const struct sockaddr *)addr,
	      sizeof(*addr)) == -1)
    return (merror("%s: %s", "connect failed", strerror(errno)));
  return (SUCCESS);
}

void		get_ip_port(char *msg, int *port, char **ip)
{
  unsigned int	i;
  unsigned int	a;

  i = 0;
  while (msg[i] && msg[i] != ' ')
    ++i;
  while (msg[i] == ' ')
    ++i;
  a = i;
  while (msg[a] && msg[a] != ':' && msg[a] != ' ' && msg[a] != '\r')
    ++a;
  *ip = strndup(&msg[i], a - i);
  if (msg[a] == ':')
    *port = atoi(&msg[a + 1]);
}

t_state			user_serv_cmd(t_client *client, t_duser *user)
{
  char			*ip;
  struct hostent	*pHostInfo;
  struct in_addr	**addr_list;

  printf("SERVER is trying to connect...\n");
  get_ip_port(client->msg, &user->network.port, &ip);
  if ((pHostInfo = gethostbyname(ip)) == NULL)
    {
      merror("%s: %s\n", "invalid address", strerror(errno));
      return (FAILURE_L1);
    }
  addr_list = (struct in_addr **)pHostInfo->h_addr_list;
  if (user_connect_to_srv(&user->network, user->network.port,
			  (addr_list[0])->s_addr))
    {
      merror("%s: %s\n", "connect failed", strerror(errno));
      return (FAILURE_L1);
    }
  printf("SERVER connected !\n");
  printf("port = %d\n", user->network.port);
  return (SUCCESS);
}

t_state		user_join_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  add_chans(user, client);
  return (SUCCESS);
}
