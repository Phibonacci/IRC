/*
** user_cmd3.c for user_cmd3 in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Thu Apr 24 14:13:58 2014 Gabriel Poulet de Grimouard
** Last update Sat Apr 26 13:54:44 2014 Gabriel Poulet de Grimouard
*/

#include <stdio.h>
#include <unistd.h>

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
  if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
    return (FAILURE_L1);
  remove_chans(user, client);
  return (SUCCESS);
}

t_state	user_list_cmd(t_client *client, t_duser *user)
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
