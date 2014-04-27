/*
** p_part.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 22:05:08 2014 Jean Fauquenot
** Last update Sun Apr 27 22:06:06 2014 Jean Fauquenot
*/

#include "parser.h"

/*
**  Parameters: <channel>{,<channel>}
*/
t_bool		p_part(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len != 1)
    return (FALSE);
  return (TRUE);
}
