/*
** p_user.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 10:44:13 2014 Jean Fauquenot
** Last update Sun Apr 27 10:44:14 2014 Jean Fauquenot
*/

#include "parser.h"

/*
** Parameters: <username> <hostname> <servername> <realname>
*/
t_bool		p_user(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 4 || len > 4)
    return (FALSE);
  return (TRUE);
}
