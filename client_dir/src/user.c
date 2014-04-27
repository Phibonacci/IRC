/*
** user.c for user in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:15:50 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 16:25:12 2014 Gabriel Poulet de Grimouard
*/

#include <unistd.h>
#include <stdlib.h>

#include "user.h"
#include "client.h"
#include "usual.h"

t_duser		*user_create(void)
{
  t_duser	*this;

  if (!(this = malloc(sizeof(*this))))
    exit(EXIT_FAILURE);
  this->nick[0] = '\0';
  this->realname[0] = '\0';
  this->hostname[0] = '\0';
  this->lchans = list_new();
  this->mode = 0;
  this->network.fd = -1;
  this->network.port = 6667;
  return (this);
}

void		client_init(t_client *client)
{
  client->quit = FALSE;
  client->towrite = FALSE;
  FD_ZERO(&client->fd_write);
  client->cmd = NULL;
  client->len_msg = 0;
  client->ip = 0;
  client->port = 4242;
  client->fxchg.fd = -1;
  client->fxchg.ip = 0;
  client->fxchg.port = 0;
}
