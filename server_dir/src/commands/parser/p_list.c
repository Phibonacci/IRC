/*
** p_list.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 19:28:46 2014 Jean Fauquenot
** Last update Sun Apr 27 20:17:27 2014 Jean Fauquenot
*/

#include "parser.h"

/*
**  Parameters: [<channel>{,<channel>} [<server>]]
*/
t_bool		p_list(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 0 || len > 2)
    return (FALSE);
  return (TRUE);
}
