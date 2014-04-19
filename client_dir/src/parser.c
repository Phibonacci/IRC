/*
** parser.c for parser in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Thu Apr 17 18:48:21 2014 Gabriel Poulet de Grimouard
** Last update Fri Apr 18 20:15:06 2014 Gabriel Poulet de Grimouard
*/

#define  _XOPEN_SOURCE 700
#include <string.h>
#include <strings.h>

#include "error.h"
#include "user.h"
#include "client.h"

static const	t_cmd	g_tab_cmd[] =
  {
    {"/j", "/join", "JOIN"},
    {"", "/server", "SERVER"},
    {"/n", "/nick", "NICK"},
    {"/l", "/list", "LIST"},
    {"", "/part", "PART"},
    {"", "/quit", "QUIT"},
    {"", "/user", "USER"},
    {"", "/msg", "PRIVMSG"},
    {"", "/send_file", ""},
    {"", "/accept_file", ""},
  };

static char	*recup_cmd(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    i++;
  return (strndup(str, i));
}

static int	replace_cmd_in_buf(t_client *client, const char *to_repl,
				   const char *repl_by)
{
  unsigned int	i;

  i = strlen(repl_by);
  memmove(&client->msg[0] + i - strlen(to_repl), &client->msg[0], 510 - i);
  strncpy(&client->msg[0], repl_by, i);
  printf("%s\n", client->msg);
  return (0);
}

int		parse_cmd(t_client *client)
{
  unsigned int	i;
  char		*cmd;

  i = LEN(g_tab_cmd);
  if (!(cmd = recup_cmd(client->msg)))
    return (0);
  while (i--)
    {
      if (!strcasecmp(cmd, g_tab_cmd[i].shr_cmd))
	return (replace_cmd_in_buf(client, g_tab_cmd[i].shr_cmd, g_tab_cmd[i].trad));
      if (!strcasecmp(cmd, g_tab_cmd[i].cmd))
	return (replace_cmd_in_buf(client, g_tab_cmd[i].cmd, g_tab_cmd[i].trad));
    }
  if (client->msg[0] != '/')
    return (replace_cmd_in_buf(client, "", "PRIVMSG "));
  merror("invalid command");
  return (0);
}