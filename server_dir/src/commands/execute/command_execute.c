/*
** command_execute.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 17:15:51 2014 Jean Fauquenot
** Last update Thu Apr 24 22:19:14 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

/*
** 4.1.2 Nick message
**
**   Command: NICK
**   Parameters: <nickname> [ <hopcount> ]
**
** Well... I will certainly not handle <hopcount>
** Crazy or what ?
*/
t_bool		e_nick(t_duser *user, t_cmd *cmd)
{
  if (!cmd->params[0])
    return (FALSE);
  if (user->nick[0])
    write_to_client(user, ":%s NICK %.9s\r\n", user->nick, cmd->params[0]);
  else
    write_to_client(user, ": NICK %.9s\r\n", cmd->params[0]);
  bzero(user->nick, USER_NICK_LEN + 1);
  strncpy(user->nick, cmd->params[0], USER_NICK_LEN);
  return (TRUE);
}

/*
** 4.1.3 User message
**
**
** Command: USER
** Parameters: <username> <hostname> <servername> <realname>
*/
t_bool		e_user(t_duser *user, t_cmd *cmd)
{
  strncpy(&(user->realname[0]), cmd->params[3], USER_REALNAME_LEN);
  user->username[0] = '~';
  strncpy(&(user->username[1]), cmd->params[0], USER_USERNAME_LEN -1);
  strncpy(&(user->hostname[0]), cmd->params[1], USER_HOSTNAME_LEN);
  write_to_client(user,
		  ":%s 001 %s :%s %s@%s\r\n",
		  SERVER_NAME,
		  user->nick,
		  RPL_WELCOME,
		  user->username, user->hostname);
  return (TRUE);
}

/*
** 4.2.3 Mode message
**
**
**      Command: MODE
**
**   The MODE command is a dual-purpose command in IRC.  It allows both
**   usernames and channels to have their mode changed.  The rationale for
**   this choice is that one day nicknames will be obsolete and the
**   equivalent property will be the channel.
**
**   When parsing MODE messages, it is recommended that the entire message
**   be parsed first and then the changes which resulted then passed on.
**
********************************************************************************
**
** 4.2.3.1 Channel modes
**
**
**   Parameters: <channel> {[+|-]|o|p|s|i|t|n|b|v} [<limit>] [<user>]
**               [<ban mask>]
** The various modes available for channels are as follows:
**
**           o - give/take channel operator privileges;
**           p - private channel flag;
**           s - secret channel flag;
**           i - invite-only channel flag;
**           t - topic settable by channel operator only flag;
**           n - no messages to channel from clients on the outside;
**           m - moderated channel;
**           l - set the user limit to channel;
**           b - set a ban mask to keep users out;
**           v - give/take the ability to speak on a moderated channel;
**           k - set a channel key (password).
**
********************************************************************************
**
**   Parameters: <nickname> {[+|-]|i|w|s|o}
**
**   The available modes are as follows:
**
**           i - marks a users as invisible;
**           s - marks a user for receipt of server notices;
**           w - user receives wallops;
**           o - operator flag.
**
*/
t_bool		e_mode(t_duser *user, t_cmd *cmd)
{
  (void)user;
  (void)cmd;
  return (TRUE);
}

t_bool		e_whois(t_duser *user, t_cmd *cmd)
{
  (void)user;
  (void)cmd;
  return (TRUE);
}

/*
** 4.6.2 Ping message
**
**
**      Command: PING
**   Parameters: <server1> [<server2>]
*/
t_bool		e_ping(t_duser *user, t_cmd *UNUSED(cmd))
{
  write_to_client(user, "PONG %s\r\n", SERVER_NAME);
  return (TRUE);
}

t_bool		command_execute(t_duser *user, t_cmd *cmd)
{
  if (cmd->exec(user, cmd) == FALSE)
    return (FALSE);
  return (TRUE);
}
