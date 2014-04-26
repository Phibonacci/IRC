/*
** l_command.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 18:02:55 2014 Jean Fauquenot
** Last update Wed Apr 23 17:43:27 2014 Jean Fauquenot
*/

#include	"lexer.h"

/*
**   <command>  ::= <letter> { <letter> } | <number> <number> <number>
*/
t_bool		l_command(char **scmd, t_cmd *cmd)
{
  size_t	i;

  cmd->command = *scmd;
  if (l_letter(scmd, cmd) == TRUE)
    {
      while (l_letter(scmd, cmd) == TRUE);
    }
  else if (l_number(scmd, cmd) == TRUE)
    {
      i = 0;
      while (l_number(scmd, cmd) == TRUE && i < 3)
	++i;
    }
  else
    {
      return (FALSE);
    }
  return (TRUE);
}
