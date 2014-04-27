/*
** e_nick.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 14:08:29 2014 Jean Fauquenot
** Last update Sun Apr 27 18:39:14 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

static t_bool	is_valid_nick(t_duser_l *clist, t_duser *user, char *nick)
{
  if (nick[0] == '\0' || strlen(nick) > USER_NICK_LEN)
	{
	  error_to_client(user, 432, "%s :Erroneous NickName.", nick);
	  return (FALSE);
	}
  while (clist)
    {
      if (strcmp(nick, clist->data.nick) == 0)
	{
	  error_to_client(user, 433, "%s :NickName is already in use.", nick);
	  return (FALSE);
	}
      clist = clist->next;
    }
  return (TRUE);
}

/*
** 4.1.2 Nick message
**
**   Command: NICK
**   Parameters: <nickname> [ <hopcount> ]
**
** Well... I will certainly not handle <hopcount>
** Crazy or what ?
*/
t_state		e_nick(t_irc *irc, t_duser *user, t_cmd *cmd)
{
  if (!cmd->params[0]
      || !is_valid_nick(irc->users, user, cmd->params[0]))
    return (SUCCESS);
  if (user->nick[0])
    write_to_client(user, ":%s NICK %.16s\r\n", user->nick, cmd->params[0]);
  bzero(user->nick, USER_NICK_LEN + 1);
  strncpy(user->nick, cmd->params[0], USER_NICK_LEN);
  return (SUCCESS);
}
