/*
** user_cmd2.c for user_cmd in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Mon Apr 21 19:58:40 2014 Gabriel Poulet de Grimouard
** Last update Sat Apr 26 16:49:54 2014 Gabriel Poulet de Grimouard
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "client.h"
#include "user.h"
#include "usual.h"
#include "error.h"

static void insert_chan(t_client *client, char *chan_name)
{
  unsigned int	i;
  unsigned int	chan_len;
  unsigned int	chang;

  chan_len = strlen(chan_name);
  i = strlen(client->cmd);
  memmove(&client->msg[0] + i + chan_len + 2,
	  &client->msg[0] + i, 510 - i - chan_len);
  chang = (client->msg[i] == ' ' ? 1 : 0);
  strncpy(&client->msg[i] + chang, chan_name, chan_len);
  client->msg[i + chang + strlen(chan_name)] = ' ';
  client->msg[i + chang + strlen(chan_name) + 1] = ':';
  client->len_msg = strlen(client->msg);
}

static void	make_msg(t_client *client)
{
  unsigned int	i;

  i = strlen(client->cmd);
  while (client->msg[i] == ' ')
    i++;
  while (client->msg[i] && client->msg[i] != ' ')
    i++;
  if (!client->msg[i])
    return ;
  i++;
  memmove(&client->msg[i] + 1, &client->msg[i], 510 - i - 1);
  client->msg[i] = ':';
}

t_state		user_privmsg_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  if (user->network.fd != -1)
    {
      make_msg(client);
      if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
	return (FAILURE_L1);
    }
  return (SUCCESS);
}

t_state	user_msg_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  if (user->network.fd != -1)
    {
      if (user->lchans->count > 0)
	insert_chan(client, ((t_chan*)user->lchans->first->val.ptr)->name);
      if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
	return (FAILURE_L1);
    }
  return (SUCCESS);
}

t_state	user_nick_cmd(t_client *client, t_duser *user)
{
  char	*nick;

  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  if (user->network.fd != -1)
    if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
      return (FAILURE_L1);
  nick = client->msg + strlen(client->cmd);
  while (*nick && *nick == ' ')
    ++nick;
  strncpy(user->nick, nick, 16);
  return (SUCCESS);
}

t_state	user_user_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  if (user->network.fd != -1)
    if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
      return (FAILURE_L1);
  return (SUCCESS);
}

t_state user_quit_cmd(t_client *client, t_duser *user)
{
  if (user->network.fd == -1)
    {
      printf("You are not connected to a server !\n");
      return (FAILURE_L1);
    }
  if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
    return (FAILURE_L1);
  close(user->network.fd);
  free(user);
  user = user_create();
  return (SUCCESS);
}
