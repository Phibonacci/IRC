/*
** p_join.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 10:45:11 2014 Jean Fauquenot
** Last update Sun Apr 27 10:47:59 2014 Jean Fauquenot
*/

#include "parser.h"

/*
** Parameters: <channel>{,<channel>} [<key>{,<key>}]
*/
t_bool		p_join(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 1 || len > 2)
    return (FALSE);
  return (TRUE);
}
