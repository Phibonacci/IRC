/*
** l_message.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 17:45:37 2014 Jean Fauquenot
** Last update Wed Apr 23 17:41:09 2014 Jean Fauquenot
*/

#include	"lexer.h"

t_bool		(*g_l_message_aux[])(char **, t_cmd *) =
{
  &l_command,
  &l_params,
  &l_crlf
};

/*
**   <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
*/
t_bool		l_message_opt(char **scmd, t_cmd *cmd)
{
  if (**scmd == ':')
    {
      ++(*scmd);
      if (l_prefix(scmd, cmd) == TRUE)
	l_space(scmd, cmd);
      else
	return (FALSE);
    }
  return (TRUE);
}

/*
**   <message>  ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
*/
t_bool		l_message(char **scmd, t_cmd *cmd)
{
  size_t	i;

  if (l_message_opt(scmd, cmd) == FALSE)
    return (FALSE);
  i = 0;
  while (i < LEN(g_l_message_aux))
    {
      if (g_l_message_aux[i](scmd, cmd) == FALSE)
	return (FALSE);
      ++i;
    }
  return (TRUE);
}
