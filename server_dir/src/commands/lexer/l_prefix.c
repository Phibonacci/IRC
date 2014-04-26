/*
** l_prefix.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 17:55:11 2014 Jean Fauquenot
** Last update Wed Apr 23 12:37:18 2014 Jean Fauquenot
*/

#include	"lexer.h"

static t_bool	l_prefix_nick(char **scmd, t_cmd *cmd)
{
  if (l_letter(scmd, cmd) == TRUE)
    while (l_letter(scmd, cmd) == TRUE);
  else
    return (FALSE);
  return (TRUE);
}

static t_bool	l_prefix_host(char **scmd, t_cmd *UNUSED(cmd))
{
  while (**scmd != ' ' && **scmd != '\0')
    ++(*scmd);
  return (TRUE);
}

/*
**  Since we don't want to follow the whole hostname rfc952,
**  we currently 'only' support the freenode's formatage
**   https://tools.ietf.org/html/rfc952
**  freenode:
**  <prefix>   ::= '~' 'nick' '@' 'host'
**  rfc1459:
**   <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
*/
t_bool		l_prefix(char **scmd, t_cmd *cmd)
{
  cmd->prefix = *scmd;
  if (**scmd == '~')
    {
      ++(*scmd);
      if (l_prefix_nick(scmd, cmd) == FALSE)
	return (FALSE);
      if (**scmd == '@')
	++(*scmd);
      else
	return (FALSE);
      if (l_prefix_host(scmd, cmd) == FALSE)
	return (FALSE);
    }
  else
    return (FALSE);
  return (TRUE);
}
