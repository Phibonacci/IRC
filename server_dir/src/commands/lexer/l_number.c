/*
** l_number.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Wed Apr 23 06:02:00 2014 Jean Fauquenot
** Last update Wed Apr 23 06:30:59 2014 Jean Fauquenot
*/

#include	"lexer.h"

/*
**   <number>     ::= '0' ... '9'
*/
t_bool		l_number(char **scmd, t_cmd *UNUSED(cmd))
{
  if (**scmd >= '0' && **scmd <= '9')
    ++(*scmd);
  else
    return (FALSE);
  return (TRUE);
}
