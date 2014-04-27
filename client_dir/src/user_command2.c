/*
** user_command2.c for user_command in /home/drdrak/rendu/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Sun Apr 27 21:07:00 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 21:56:53 2014 Gabriel Poulet de Grimouard
*/

#include <string.h>
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
    {"WHO", &user_user_cmd},
    {"USER", &user_user_cmd},
    {"PRIVMSG", &user_privmsg_cmd},
    {"PRIVMSG ", &user_msg_cmd},
    {"ACTION", &user_msg_cmd},
    {"IPPORT", &set_ip_port},
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

t_state		read_cmd(t_client *client, t_duser *user)
{
  if ((client->len_msg = read(0, client->msg, 510)) <= 0)
    {
      merror("%s: %s", "read failed", strerror(errno));
      return (FAILURE);
    }
  client->msg[client->len_msg - 1] = '\r';
  client->msg[client->len_msg] = '\n';
  client->msg[client->len_msg + 1] = '\0';
  if (parse_cmd(client) == -1)
    return (SUCCESS);
  user_exec_cmd(client, user);
  return (SUCCESS);
}
