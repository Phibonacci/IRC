/*
** p_ping.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 10:44:56 2014 Jean Fauquenot
** Last update Sun Apr 27 10:44:58 2014 Jean Fauquenot
*/

#include "parser.h"

/*
** Parameters: <server1> [<server2>]
**
** [<server2>] ignored
*/
t_bool		p_ping(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 1 || len > PARAMS_MAX)
    return (FALSE);
  return (TRUE);
}
