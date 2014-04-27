/*
** user_cmd3.c for user_cmd3 in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Thu Apr 24 14:13:58 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 22:52:36 2014 Gabriel Poulet de Grimouard
*/

#define _BSD_SOURCE
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "chan.h"
#include "client.h"
#include "usual.h"
#include "user.h"

t_state		user_part_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  remove_chans(user, client);
  return (SUCCESS);
}

t_state		user_list_cmd(t_client *client, t_duser *user)
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

t_state		user_nick_cmd(t_client *client, t_duser *user)
{
  char		*nick;

  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  nick = client->msg + strlen(client->cmd);
  while (*nick && *nick == ' ')
    ++nick;
  strncpy(user->nick, nick, 15);
  return (SUCCESS);
}

t_state		user_user_cmd(t_client *client, t_duser *user)
{
  (void)client;
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  return (SUCCESS);
}
