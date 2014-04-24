/*
** l_middle.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 19:52:59 2014 Jean Fauquenot
** Last update Thu Apr 24 00:27:17 2014 Jean Fauquenot
*/

#include	"lexer.h"

t_bool		match_char_of_string(char c, char const *src)
{
  size_t	i;

  i = 0;
  while (src[i])
    {
      if (c == src[i])
	return (TRUE);
      ++i;
    }
  return (FALSE);
}

/*
**   <middle>   ::= <Any *non-empty* sequence of octets not including SPACE
**                   or NUL or CR or LF, the first of which may not be ':'>
*/
t_bool			l_middle(char **scmd, t_cmd *UNUSED(cmd))
{
  static char const	c_middle[] = ": \r\n";

  if (!match_char_of_string(**scmd, &(c_middle[0])) && **scmd)
    {
      ++(*scmd);
      while (!match_char_of_string(**scmd, &(c_middle[1])) && **scmd)
	{
	  ++(*scmd);
	}
    }
  else
    return (FALSE);
  return (TRUE);
}
