/*
** command_parser.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 14:06:59 2014 Jean Fauquenot
** Last update Thu Apr 24 20:42:11 2014 Jean Fauquenot
*/

#include	"parser.h"
#include	"error_command.h"
#include	"execute.h"

#include	<string.h>

static t_parser_cmd const	g_command_parser[] =
  {
    {1, "NICK", &e_nick},
    {2, "USER", &e_user},
    {3, "MODE", &e_mode},
    {1, "WHOIS", &e_whois},
    {1, "PING", &e_ping}
  };

int		array_ptr_len(char **array)
{
  size_t	len;

  len = 0;
  while (array[len])
    {
      ++len;
    }
  return (len);
}

t_bool		command_parser(t_duser *user, t_cmd *cmd)
{
  size_t	i;

  i = 0;
  while (i < LEN(g_command_parser))
    {
      if (strcmp(cmd->command, g_command_parser[i].name) == 0)
	{
	  cmd->exec = g_command_parser[i].exec;
	  return (TRUE);
	}
      ++i;
    }
  write_to_client(user, "%s: %s", cmd->command, ERR_UNKNOWNCOMMAND);
  return (FALSE);
}
