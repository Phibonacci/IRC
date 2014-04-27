/*
** user_cmd3.c for user_cmd3 in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Thu Apr 24 14:13:58 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 16:26:30 2014 Gabriel Poulet de Grimouard
*/

#define _BSD_SOURCE
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "chan.h"
#include "client.h"
#include "usual.h"
#include "user.h"

t_state	user_part_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  remove_chans(user, client);
  return (SUCCESS);
}

t_state	user_list_cmd(t_client *client, t_duser *user)
{
  (void)client;
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  return (SUCCESS);
}

t_state			set_ip_port(t_client *client, t_duser *user)
{
  char			*ip;
  struct hostent	*pHostInfo;
  struct in_addr	**addr_list;

  (void)user;
  get_ip_port(client->msg, &client->port, &ip);
  if ((pHostInfo = gethostbyname(ip)) == NULL)
    return (FAILURE_L1);
  addr_list = (struct in_addr **)pHostInfo->h_addr_list;
  client->ip = htonl((addr_list[0])->s_addr);
  return (SUCCESS);
}

static void	send_get_params(t_client *client)
{
  unsigned int	i;
  unsigned int	a;

  i = strlen(client->cmd) + 1;
  a = i;
  while (client->msg[a] != ' ')
    a++;
  strncpy(&client->fxchg.nicksend[0], &client->msg[i], (a - i > 15 ? 15 : a - i));
  client->fxchg.nicksend[(a - i > 15 ? 15 : a - i)] = '\0';
  while (client->msg[a] == ' ')
    a++;
  i = a;
  while (client->msg[a] != ' ' && client->msg[a] != '\r')
    a++;
  strncpy(&client->fxchg.fname[0], &client->msg[i], (a - i > 49 ? 49 : a - i));
  client->fxchg.fname[(a - i > 49 ? 49 : a - i)] = '\0';
}

t_state		connection_start(t_client *client)
{
  struct protoent	*pe;
  struct sockaddr_in	sin;

  pe = getprotobyname("TCP");
  if ((client->fxchg.fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (FAILURE_L1);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(client->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(client->fxchg.fd, (const struct sockaddr *)&sin,
	   sizeof(sin)) == -1)
    return (FAILURE_L1);
  listen(client->fxchg.fd, 1);
  client->fxchg.readd = FALSE;
  return (SUCCESS);
}

t_state		user_send_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  if (client->fxchg.is_inuse == 1)
    return (FAILURE_L1);
  send_get_params(client);
  snprintf(client->msg, 510, "PRIVMSG %s %cDCC SEND %s %d %d %d%c",
	   client->fxchg.nicksend, 1, client->fxchg.fname,
	   client->ip, client->port, 42, 1);
  client->msg[strlen(client->msg) + 2] = '\0';
  client->msg[strlen(client->msg)] = '\r';
  client->msg[strlen(client->msg) - 1] = '\n';
  client->len_msg = strlen(client->msg);
  client->cmd = "PRIVMSG";
  user_privmsg_cmd(client, user);
  connection_start(client);
  return (SUCCESS);
}

/*
** SEND drdrak toto.c
** => PRIVMSG drdrak \001DCC SEND toto.c ip port
** ACCEPT drdrak2
** => PRIVMSG drdrak2 \001DCC ACCEPT toto.c ip\001
*/

t_state		user_accept_cmd(t_client *client, t_duser *user)
{
  t_network	net;

  (void)user;
  if (client->fxchg.ip == 0 || client->fxchg.port == 0)
    {
      printf("Accept failed\n");
      return (FAILURE_L1);
    }
  user_connect_to_srv(&net, client->fxchg.port, client->fxchg.ip);
  client->fxchg.fd = net.fd;
  return (SUCCESS);
}

