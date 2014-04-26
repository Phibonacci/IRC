/*
** parser.c for parser in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Thu Apr 17 18:48:21 2014 Gabriel Poulet de Grimouard
** Last update Sat Apr 26 15:00:26 2014 Gabriel Poulet de Grimouard
*/

#define  _XOPEN_SOURCE 700
#include <string.h>
#include <strings.h>
#include <stdio.h>

#include "error.h"
#include "user.h"
#include "client.h"

static	t_cmd	g_tab_cmd[] =
  {
    {"/join", "JOIN", "/j"},
    {"/server", "SERVER", ""},
    {"/nick", "NICK", "/n"},
    {"/list", "LIST", "/l"},
    {"/part", "PART", ""},
    {"/quit", "QUIT", ""},
    {"/user", "USER", ""},
    {"/msg", "PRIVMSG", ""},
    {"/me", "ACTION", ""},
    {"/send_file", "send_file", ""},
    {"/accept_file", "accept_file", ""},
  };

static char	*recup_cmd(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i] && str[i] != ' ' && str[i] != '\t')
    i++;
  return (strndup(str, i));
}

/*
** le 2e strlen est pas necessaire un calcul mathematique serai plus optimise.
** de plus c'est dans une boucle critique d'optimisation.
** a faire des que le reste fonctionne bien.
*/
static int	replace_cmd_in_buf(t_client *client, const char *to_repl,
				   char *repl_by)
{
  unsigned int	i;

  i = strlen(repl_by);
  memmove(&client->msg[0] + i - strlen(to_repl), &client->msg[0], 510 - i);
  strncpy(&client->msg[0], repl_by, i);
  printf("%s\n", client->msg);
  if (strcmp(repl_by, "PRIVMSG "))
    client->cmd = repl_by;
  else
    client->cmd = "PRIVMSG ";
  client->len_msg = strlen(client->msg);
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
  return (-1);
}
