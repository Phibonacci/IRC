/*
** p_mode.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 10:44:22 2014 Jean Fauquenot
** Last update Sun Apr 27 10:44:24 2014 Jean Fauquenot
*/

#include "parser.h"

/*
** Parameters: <channel> {[+|-]|o|p|s|i|t|n|b|v} [<limit>] [<user>]
**             [<ban mask>]
**             | <nickname> {[+|-]|i|w|s|o}
*/
t_bool		p_mode(t_cmd *cmd)
{
  int		len;

  len = array_ptr_len(cmd->params);
  if (len < 2 || len > 5)
    return (FALSE);
  return (TRUE);
}
