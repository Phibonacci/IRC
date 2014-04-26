/*
** l_trailing.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 19:56:45 2014 Jean Fauquenot
** Last update Thu Apr 24 13:54:18 2014 Jean Fauquenot
*/

#include	"lexer.h"

/*
**   <trailing> ::= <Any, possibly *empty*, sequence of octets not including
**                   NUL or CR or LF>
*/
t_bool			l_trailing(char **scmd, t_cmd *UNUSED(cmd))
{
  static char const	c_ntrailing[] = "\r\n";

  if (!match_char_of_string(**scmd, &(c_ntrailing[0])) && **scmd)
    {
      while (!match_char_of_string(**scmd, &(c_ntrailing[0])) && **scmd)
	{
	  ++(*scmd);
	}
    }
  else
    return (FALSE);
  return (TRUE);
}
