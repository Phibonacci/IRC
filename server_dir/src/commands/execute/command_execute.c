/*
** command_execute.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 17:15:51 2014 Jean Fauquenot
** Last update Sun Apr 27 13:35:57 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

t_state		command_execute(t_irc *irc, t_duser *user, t_cmd *cmd)
{
  if (cmd->exec(irc, user, cmd) == FAILURE)
    return (FAILURE);
  return (TRUE);
}
