/*
** e_user.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 15:20:26 2014 Jean Fauquenot
** Last update Sun Apr 27 19:25:07 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

/*
** 4.1.3 User message
**
**
** Command: USER
** Parameters: <username> <hostname> <servername> <realname>
*/
t_state		e_user(t_irc *UNUSED(irc), t_duser *user, t_cmd *cmd)
{
  if (!user->nick[0])
    {
      return (SUCCESS);
    }
  strncpy(&(user->realname[0]), cmd->params[3], USER_REALNAME_LEN);
  user->username[0] = '~';
  strncpy(&(user->username[1]), cmd->params[0], USER_USERNAME_LEN - 1);
  strncpy(&(user->hostname[0]), cmd->params[1], USER_HOSTNAME_LEN);
  write_to_client(user,
		  ":%s 001 %s :%s %s@%s\r\n",
		  SERVER_NAME,
		  user->nick,
		  RPL_WELCOME,
		  user->username, user->hostname);
  user->identify = TRUE;
  return (SUCCESS);
}
