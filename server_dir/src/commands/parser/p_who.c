/*
** p_who.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 21:33:40 2014 Jean Fauquenot
** Last update Sun Apr 27 21:39:32 2014 Jean Fauquenot
*/

#include "parser.h"

/*
** Parameters: [<name> [<o>]]
*/
t_bool		p_who(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 1 || len > 2)
    return (FALSE);
  return (TRUE);
}
