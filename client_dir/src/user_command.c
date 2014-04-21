/*
** user_command.c for user_cnd in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:41:59 2014 Gabriel Poulet de Grimouard
** Last update Mon Apr 21 14:55:40 2014 Gabriel Poulet de Grimouard
*/

#include <unistd.h>
#include <string.h>

#include "client.h"
#include "user.h"
#include "usual.h"

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
    {"send_file", &user_send_cmd},
    {"accept_file", &user_accept_cmd}
  };

static int	user_exec_cmd(t_client *client, t_user *user)
{
  unsigned int	i;

  i = LEN(g_tab_fnct);
  while (i--)
    if (!strcmp(g_tab_fnct[i].cmd, client->cmd))
      return (g_tab_fnct[i].fnct(client, user));
  user_msg_cmd(client, user);
  return (0);
}

void		user_cmd(t_user *user)
{
  t_client	client;

  client_init(&client);
  (void)user;
  while (client.quit == FALSE)
    {
      if ((client.len_msg = read(0, client.msg, 510)) <= 0)
	return ;
      client.msg[client.len_msg] = '\r';
      client.msg[client.len_msg + 1] = '\0';
      if (parse_cmd(&client) == -1)
	continue ;
      user_exec_cmd(&client, user);
    }
}
