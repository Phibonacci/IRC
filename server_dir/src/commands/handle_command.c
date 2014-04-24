/*
** handle_command.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 02:01:43 2014 Jean Fauquenot
** Last update Thu Apr 24 17:25:08 2014 Jean Fauquenot
*/

#include	"command.h"
#include	"error.h"

#include	<string.h>

t_state		handle_command(t_duser *user, char *scmd)
{
  t_cmd		cmd;

  bzero(&cmd, sizeof(cmd));
  if ((command_lexer(scmd, &cmd)) != TRUE)
    return (SUCCESS);
  if ((command_parser(user, &cmd)) != TRUE)
    return (FALSE);
  command_execute(user, &cmd);
  return (SUCCESS);
}
