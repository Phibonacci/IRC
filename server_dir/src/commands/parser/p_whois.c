/*
** p_whois.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 10:44:41 2014 Jean Fauquenot
** Last update Sun Apr 27 10:44:42 2014 Jean Fauquenot
*/

#include "parser.h"

/*
** Parameters: [<server>] <nickmask>[,<nickmask>[,...]]
*/
t_bool		p_whois(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 1 || len > PARAMS_MAX)
    return (FALSE);
  return (TRUE);
}
