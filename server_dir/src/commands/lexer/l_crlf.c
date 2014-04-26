/*
** l_crlf.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 18:25:15 2014 Jean Fauquenot
** Last update Wed Apr 23 13:58:13 2014 Jean Fauquenot
*/

#include	"lexer.h"

/*
**   <crlf>     ::= CR LF
*/
t_bool		l_crlf(char **scmd, t_cmd *UNUSED(cmd))
{
  if (**scmd == '\r')
    {
      **scmd = '\0';
      ++(*scmd);
      if (**scmd == '\n')
	++(*scmd);
	return (TRUE);
    }
  return (FALSE);
}
