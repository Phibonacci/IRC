/*
** p_nick.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 15:37:31 2014 Jean Fauquenot
** Last update Sun Apr 27 10:45:07 2014 Jean Fauquenot
*/

#include "parser.h"

/*
** Parameters: <nickname> [ <hopcount> ]
*/
t_bool		p_nick(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 1 || len > PARAMS_MAX)
    return (FALSE);
  return (TRUE);
}
