/*
** user_cmd.c for user in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Sat Apr 19 16:41:29 2014 Gabriel Poulet de Grimouard
** Last update Sat Apr 26 13:34:25 2014 Gabriel Poulet de Grimouard
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

static int		user_connect_to_srv(t_duser *user,
					    int port, struct in_addr *ip)
{
  struct protoent	*pe;
  struct sockaddr_in	*addr;

  addr = &user->network.addr;
  pe = getprotobyname("TCP");
  if ((user->network.fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (merror("%s: %s", "socket failed", strerror(errno)));
  addr->sin_family = AF_INET;
  addr->sin_port = htons(port);
  addr->sin_addr.s_addr = inet_addr(inet_ntoa(*ip));
  if (connect(user->network.fd, (const struct sockaddr *)addr,
	      sizeof(*addr)) == -1)
    return (merror("%s: %s", "connect failed", strerror(errno)));
  return (SUCCESS);
}

static void	get_ip_port(char *msg, int *port, char **ip)
{
  unsigned int	i;
  unsigned int	a;

  i = 0;
  while (msg[i] && msg[i] != ' ')
    ++i;
  while (msg[i] == ' ')
    ++i;
  a = i;
  while (msg[a] && msg[a] != ':' && msg[a] != '\n' && msg[a] != '\r')
    ++a;
  *ip = strndup(&msg[i], a - i);
  if (msg[a] == ':')
    *port = atoi(&msg[a + 1]);
}

t_state			user_serv_cmd(t_client *client, t_duser *user)
{
  char			*ip;
  struct hostent*	pHostInfo;
  struct in_addr	**addr_list;

  printf("SERVER is trying to connect...\n");
  get_ip_port(client->msg, &user->network.port, &ip);
  if ((pHostInfo = gethostbyname(ip)) == NULL)
    return (FAILURE_L1);
  addr_list = (struct in_addr **)pHostInfo->h_addr_list;
  if (!user_connect_to_srv(user, user->network.port, addr_list[0]))
    return (FAILURE_L1);
  if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
    return (FAILURE_L1);
  printf("SERVER connected !\n");
  return (SUCCESS);
}

t_state		user_join_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
    return (FAILURE_L1);
  add_chans(user, client);
  return (SUCCESS);
}
