/*
** command_parser.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 14:06:59 2014 Jean Fauquenot
** Last update Sun Apr 27 22:06:30 2014 Jean Fauquenot
*/

#include	"parser.h"
#include	"error_command.h"
#include	"execute.h"

#include	<string.h>

static t_parser_cmd const	g_command_parser[] =
  {
    {1, "NICK", &e_nick, &p_nick},
    {2, "USER", &e_user, &p_user},
    {3, "MODE", &e_mode, &p_mode},
    {4, "WHOIS", &e_whois, &p_whois},
    {5, "PING", &e_ping, &p_ping},
    {6, "JOIN", &e_join, &p_join},
    {7, "PRIVMSG", &e_privmsg, &p_privmsg},
    {8, "LIST", &e_list, &p_list},
    {9, "WHO", &e_who, &p_who},
    {10, "PART", &e_part, &p_part}
  };

t_bool		command_parser(t_duser *user, t_cmd *cmd)
{
  size_t	i;

  i = 0;
  while (i < LEN(g_command_parser))
    {
      if (strcmp(cmd->command, g_command_parser[i].name) == 0)
	{
	  if (!g_command_parser[i].parse(cmd))
	    {
	      error_to_client(user, 461, "%s :Not enough parameters",
			      cmd->command);
	      return (FALSE);
	    }
	  cmd->exec = g_command_parser[i].exec;
	  return (TRUE);
	}
      ++i;
    }
  error_to_client(user, 421, "%s :Unknown command", cmd->command);
  return (FALSE);
}
