/*
** l_letter.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Wed Apr 23 06:01:52 2014 Jean Fauquenot
** Last update Wed Apr 23 06:30:46 2014 Jean Fauquenot
*/

#include	"lexer.h"

/*
**   <letter>     ::= 'a' ... 'z' | 'A' ... 'Z'
*/
t_bool		l_letter(char **scmd, t_cmd *UNUSED(cmd))
{
  if ((**scmd >= 'a' && **scmd <= 'z')
      || (**scmd >= 'A' && **scmd <= 'Z'))
    ++(*scmd);
  else
    return (FALSE);
  return (TRUE);
}
