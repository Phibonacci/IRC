/*
** e_mode.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 15:07:43 2014 Jean Fauquenot
** Last update Sun Apr 27 19:24:49 2014 Jean Fauquenot
*/

#include	"execute.h"

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
t_state		e_mode(t_irc *UNUSED(irc), t_duser *user, t_cmd *cmd)
{
  if (user->identify == FALSE)
    return (SUCCESS);
  (void)user;
  (void)cmd;
  return (SUCCESS);
}
