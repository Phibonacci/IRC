/*
** user_cmd.c for user in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Sat Apr 19 16:41:29 2014 Gabriel Poulet de Grimouard
** Last update Mon Apr 21 19:20:48 2014 Gabriel Poulet de Grimouard
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

static int		user_connect_to_srv(t_muser *user,
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
  printf("ip = %s\n", inet_ntoa(*ip));
  addr->sin_addr.s_addr = inet_addr(inet_ntoa(*ip));
  if (connect(user->network.fd, (const struct sockaddr *)addr,
	      sizeof(*addr)) == -1)
    return (merror("%s: %s", "connect failed", strerror(errno)));
  return (SUCCESS);
}

static void	get_ip_port(char *msg, int *port, char **ip)
{
  unsigned int	i;
  int		a;

  i = 0;
  while (msg[i] && msg[i] != ' ')
    ++i;
  while (msg[i] == ' ')
    ++i;
  a = i;
  while (msg[a] && msg[a] != ':' && msg[a] != '\n' && msg[a] != '\r')
    ++a;
  *ip = strndup(&msg[i], a - i);
  printf("%s\n", *ip);
  if (msg[a] == ':')
    *port = atoi(&msg[a + 1]);
}

t_state			user_serv_cmd(t_client *client, t_muser *user)
{
  int			port;
  char			*ip;
  struct hostent*	pHostInfo;
  struct in_addr	**addr_list;

  port = 0;
  get_ip_port(client->msg, &port, &ip);
  pHostInfo = gethostbyname(ip);
  addr_list = (struct in_addr **)pHostInfo->h_addr_list;
  if (!user_connect_to_srv(user, port, addr_list[0]))
    return (FAILURE_L1);
  if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
    return (FAILURE_L1);
  return (SUCCESS);
}

t_state	user_join_cmd(t_client *client, t_muser *user)
{
  if (user->network.fd != -1)
    if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
      return (FAILURE_L1);
  return (SUCCESS);
}

t_state	user_msg_cmd(t_client *client, t_muser *user)
{
  if (user->network.fd != -1)
    if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
      return (FAILURE_L1);
  return (SUCCESS);
}

t_state	user_nick_cmd(t_client *client, t_muser *user)
{
  char	*nick;

  if (user->network.fd != -1)
    if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
      return (FAILURE_L1);
  nick = client->msg + strlen(client->cmd);
  while (*nick && *nick == ' ')
    ++nick;
  strncpy(user->nick, nick, 16);
  printf("%s\n", user->nick);
  return (SUCCESS);
}
