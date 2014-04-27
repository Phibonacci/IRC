/*
** p_privmsg.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 17:53:54 2014 Jean Fauquenot
** Last update Sun Apr 27 17:58:26 2014 Jean Fauquenot
*/

#include "parser.h"

/*
**  Parameters: <receiver>{,<receiver>} <text to be sent>
*/
t_bool		p_privmsg(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 2 || len > 2)
    return (FALSE);
  return (TRUE);
}
