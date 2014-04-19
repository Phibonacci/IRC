/*
** user.c for user in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:15:50 2014 Gabriel Poulet de Grimouard
** Last update Fri Apr 18 18:41:13 2014 Gabriel Poulet de Grimouard
*/

#include <unistd.h>
#include <stdlib.h>

#include "user.h"
#include "client.h"
#include "usual.h"

t_user		*user_create(void)
{
  t_user	*this;

  if (!(this = malloc(sizeof(*this))))
    exit(EXIT_FAILURE);
  this->nick[0] = '\0';
  this->realname[0] = '\0';
  this->hostname[0] = '\0';
  this->chans = NULL;
  this->mode = 0;
  return (this);
}

void		client_init(t_client *client)
{
  client->quit = FALSE;
}
