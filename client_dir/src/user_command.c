/*
** user_command.c for user_cnd in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:41:59 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 16:26:02 2014 Gabriel Poulet de Grimouard
*/

#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "client.h"
#include "user.h"
#include "usual.h"
#include "error.h"

static const t_fnct	g_tab_fnct[] =
  {
    {"JOIN", &user_join_cmd},
    {"SERVER", &user_serv_cmd},
    {"NICK", &user_nick_cmd},
    {"LIST", &user_list_cmd},
    {"PART", &user_part_cmd},
    {"QUIT", &user_quit_cmd},
    {"USER", &user_user_cmd},
    {"PRIVMSG", &user_privmsg_cmd},
    {"PRIVMSG ", &user_msg_cmd},
    {"ACTION", &user_msg_cmd},
    {"IPPORT", &set_ip_port},
    {"SEND", &user_send_cmd},
    {"ACCEPT", &user_accept_cmd}
  };

static int	user_exec_cmd(t_client *client, t_duser *user)
{
  unsigned int	i;

  i = LEN(g_tab_fnct);
  while (i--)
    {
      if (!strcmp(g_tab_fnct[i].cmd, client->cmd))
	return (g_tab_fnct[i].fnct(client, user));
    }
  return (0);
}

t_state	write_to_serv(t_client *client, t_duser *user)
{
  if (client->msg[0] == '\0')
    return (SUCCESS);
  if ((write(user->network.fd, client->msg, client->len_msg)) <= 0)
    return (FAILURE_L1);
  client->msg[0] = '\0';
  return (SUCCESS);
}

static void	init_select(t_client *cli, int *fd, fd_set *fd_read, t_duser *user)
{
  cli->fxchg.is_inuse = 0;
  if (user->network.fd == -1)
    *fd = 0;
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
      if (cli->fxchg.fd != -1)
	{
	  cli->fxchg.is_inuse = 1;
	  if (cli->fxchg.readd == TRUE)
	    FD_SET(cli->fxchg.fd, fd_read);
	  else
	    FD_SET(cli->fxchg.fd, &cli->fd_write);
	}
    }
}

static t_state	read_sock(t_client *client, int fd)
{
  client->len_msg = 510;
  while (client->len_msg == 510)
    {
      if ((client->len_msg = read(fd, client->msg, 510)) <= 0)
	return (FAILURE);
      (void)write(1, client->msg, client->len_msg);
      if (strncasecmp(client->msg, "ping", 4) == 0)
	if (write(fd, "pong", 4) <= 0)
	  return (FAILURE);
    }
  client->msg[0] = '\0';
  client->len_msg = 0;
  return (SUCCESS);
}

static t_state	read_cmd(t_client *client, t_duser *user)
{
  if ((client->len_msg = read(0, client->msg, 510)) <= 0)
    return (FAILURE);
  client->msg[client->len_msg - 1] = '\r';
  client->msg[client->len_msg] = '\n';
  client->msg[client->len_msg + 1] = '\0';
  if (parse_cmd(client) == -1)
    return (SUCCESS);
  user_exec_cmd(client, user);
  return (SUCCESS);
}

static t_state	write_file(t_client *client)
{
  int		fd;

  if ((fd = open(&client->fxchg.fname[0], O_WRONLY)) == -1)
    {
      close(client->fxchg.fd);
      client->fxchg.fd = -1;
      merror("%s: %s", "open failed", strerror(errno));
      return (FAILURE_L1);
    }
  client->len_msg = 510;
  while (client->len_msg == 510)
    {
      if ((client->len_msg = read(fd, client->msg, 510)) <= 0)
	{
	  merror("%s: %s", "read failed", strerror(errno));
	  break ;
	}
      (void)write(client->fxchg.fd, client->msg, client->len_msg);
    }
  client->msg[0] = '\0';
  client->len_msg = 0;
  close(fd);
  close(client->fxchg.fd);
  client->fxchg.fd = 0;
  return (SUCCESS);
}


static t_state	read_file(t_client *client)
{
  int		fd;

  if ((fd = open(&client->fxchg.fname[0], O_CREAT | O_WRONLY, 0666)) == -1)
    {
      close(client->fxchg.fd);
      client->fxchg.fd = -1;
      merror("%s: %s", "open failed", strerror(errno));
      return (FAILURE_L1);
    }
  client->len_msg = 510;
  while (client->len_msg == 510)
    {
      if ((client->len_msg = read(client->fxchg.fd, client->msg, 510)) <= 0)
	break ;
      (void)write(fd, client->msg, client->len_msg);
    }
  client->msg[0] = '\0';
  client->len_msg = 0;
  close(fd);
  close(client->fxchg.fd);
  client->fxchg.fd = 0;
  client->fxchg.ip = 0;
  client->fxchg.port = 0;
  return (SUCCESS);
}

static void	select_check(t_client *cli, t_duser *user, fd_set *fd_read)
{
  if (user->network.fd && FD_ISSET(user->network.fd, &cli->fd_write))
    write_to_serv(cli, user);
  if (cli->fxchg.fd && cli->fxchg.fd && FD_ISSET(cli->fxchg.fd,
						  &cli->fd_write))
    write_file(cli);
  if (cli->fxchg.fd && cli->fxchg.fd && FD_ISSET(cli->fxchg.fd , fd_read))
    read_file(cli);
  if (user->network.fd && (FD_ISSET(user->network.fd, fd_read)))
    if (read_sock(cli, user->network.fd) != SUCCESS)
      {
	merror("%s: %s", "server socket is down", strerror(errno));
	free(user);
	user = user_create();
      }
  if (FD_ISSET(0, fd_read))
    if (read_cmd(cli, user) == FAILURE)
      return ;
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
