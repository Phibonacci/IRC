/*
** user_command.c for user_cnd in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:41:59 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 23:26:59 2014 Gabriel Poulet de Grimouard
*/

#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "client.h"
#include "user.h"
#include "usual.h"
#include "error.h"

t_state		write_to_serv(t_client *client, t_duser *user)
{
  if (client->msg[0] == '\0')
    return (SUCCESS);
  if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
    return (FAILURE_L1);
  client->msg[0] = '\0';
  return (SUCCESS);
}

static t_state	read_sock(t_client *client, int fd, fd_set *fd_read)
{
  client->len_msg = 510;
  while (FD_ISSET(fd, fd_read) && client->len_msg == 510)
    {
      if ((client->len_msg = read(fd, client->msg, 510)) <= 0)
	return (FAILURE);
      client->msg[client->len_msg] = '\0';
      if (strncasecmp(client->msg, "ping", 4) == 0)
	{
	  if (write(fd, "pong", 4) <= 0)
	    return (FAILURE);
	}
      else
	(void)write(1, client->msg, client->len_msg);
    }
  client->msg[0] = '\0';
  client->len_msg = 0;
  return (SUCCESS);
}

static void	init_select(t_client *cli, int *fd, fd_set *fd_read,
			    t_duser *user)
{
  cli->fxchg.is_inuse = 0;
  *fd = 2;
  FD_ZERO(fd_read);
  cli->towrite = FALSE;
  FD_SET(0, fd_read);
  if (user->network.fd != -1)
    {
      FD_ZERO(&cli->fd_write);
      *fd = user->network.fd;
      FD_SET(*fd, fd_read);
      FD_SET(*fd, &cli->fd_write);
      cli->towrite = TRUE;
      if (cli->fxchg.fd != 0)
	{
	  *fd = cli->fxchg.fd;
	  cli->fxchg.is_inuse = 1;
	  if (cli->fxchg.readd == TRUE)
	    FD_SET(cli->fxchg.fd, fd_read);
	  else
	    FD_SET(cli->fxchg.fd, &cli->fd_write);
	}
    }
}

static void	select_check(t_client *cli, t_duser *user, fd_set *fd_read)
{
  if (user->network.fd && FD_ISSET(user->network.fd, &cli->fd_write))
    write_to_serv(cli, user);
  if (user->network.fd && (FD_ISSET(user->network.fd, fd_read)))
    if (read_sock(cli, user->network.fd, fd_read) != SUCCESS)
      {
	merror("%s: %s", "server socket is down", strerror(errno));
	free(user);
	user = user_create();
      }
  if (FD_ISSET(0, fd_read))
    if (read_cmd(cli, user) == FAILURE)
      cli->quit = TRUE;
}

void		user_cmd(t_duser *user)
{
  t_client	client;
  int		fd;
  fd_set	fd_read;

  client_init(&client);
  while (client.quit == FALSE)
    {
      init_select(&client, &fd, &fd_read, user);
      if (select(fd + 1, &fd_read, (client.towrite == FALSE ? NULL :
				    &client.fd_write), NULL, NULL) == -1)
	return ((void)merror("%s: %s", "select failed", strerror(errno)));
      select_check(&client, user, &fd_read);
    }
}
