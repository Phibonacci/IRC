/*
** user_command.c for user_cnd in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:41:59 2014 Gabriel Poulet de Grimouard
** Last update Sat Apr 26 15:01:25 2014 Gabriel Poulet de Grimouard
*/

#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

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
    /* {"send_file", &user_send_cmd}, */
    /* {"accept_file", &user_accept_cmd} */
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

static void	init_select(int *fd, fd_set fd_select[2], t_duser *user)
{
  *fd = 0;
  if (user->network.fd != -1)
    *fd = user->network.fd;
  FD_ZERO(&fd_select[0]);
  FD_ZERO(&fd_select[1]);
  FD_SET(0, &fd_select[0]);
  if (*fd)
    {
      if (*fd)
	{
	  FD_SET(*fd, &fd_select[0]);
	  FD_SET(*fd, &fd_select[1]);
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

void		user_cmd(t_duser *user)
{
  t_client	client;
  int		fd;
  fd_set	fd_select[2];

  client_init(&client);
  while (client.quit == FALSE)
    {
      init_select(&fd, fd_select, user);
      if (select(fd + 1, &fd_select[0], NULL, NULL, NULL) == -1)
	return ;
      if (fd && (FD_ISSET(fd, &fd_select[0])))
	{
	  if (read_sock(&client, user->network.fd) != SUCCESS)
	    {
	      merror("%s: %s", "server socket is down", strerror(errno));
	      free(user);
	      user = user_create();
	    }
	}
      if (FD_ISSET(0, &fd_select[0]))
	{
	  if (read_cmd(&client, user) == FAILURE)
	    return ;
	}
    }
}
