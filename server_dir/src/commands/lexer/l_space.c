/*
** l_space.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 18:25:29 2014 Jean Fauquenot
** Last update Wed Apr 23 06:44:22 2014 Jean Fauquenot
*/

#include	"lexer.h"

/*
**   <SPACE>    ::= ' ' { ' ' }
*/
t_bool		l_space(char **scmd, t_cmd *UNUSED(cmd))
{
  if (**scmd == ' ')
    {
      while (**scmd == ' ')
	{
	  **scmd = '\0';
	  ++(*scmd);
	}
    }
  else
    return (FALSE);
  return (TRUE);
}
