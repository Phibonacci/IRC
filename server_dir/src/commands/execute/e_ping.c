/*
** e_ping.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 15:19:50 2014 Jean Fauquenot
** Last update Sun Apr 27 19:25:18 2014 Jean Fauquenot
*/

#include	"execute.h"

/*
** 4.6.2 Ping message
**
**
**      Command: PING
**   Parameters: <server1> [<server2>]
*/
t_state		e_ping(t_irc *UNUSED(irc), t_duser *user, t_cmd *UNUSED(cmd))
{
  if (user->identify == FALSE)
    return (SUCCESS);
  write_to_client(user, "PONG %s\r\n", SERVER_NAME);
  return (SUCCESS);
}
