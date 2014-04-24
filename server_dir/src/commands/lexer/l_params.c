/*
** l_params.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 18:24:56 2014 Jean Fauquenot
** Last update Thu Apr 24 13:47:30 2014 Jean Fauquenot
*/

#include	"lexer.h"

static t_bool	add_param(char **scmd, t_cmd *cmd)
{
  size_t	i;

  i = 0;
  while (cmd->params[i])
    ++i;
  if (i >= PARAMS_MAX)
    return (FALSE);
  cmd->params[i] = *scmd;
  return (TRUE);
}

static void	remove_last_param(t_cmd *cmd)
{
  size_t	i;

  i = 0;
  while (cmd->params[i])
    ++i;
  cmd->params[(i > 0 ? i - 1 : 0)] = NULL;
}

/*
**  Tail recursive
**
**  rfc1459: PARAMS_MAX = 15
**   <params>   ::= <SPACE> [ ':' <trailing> | <middle> <params> ]PARAMS_MAX
*/
t_bool		l_params(char **scmd, t_cmd *cmd)
{
  if (l_space(scmd, cmd) == FALSE)
    return (TRUE);
  if (add_param(scmd, cmd) == FALSE)
    return (FALSE);
  if (**scmd == ':')
    {
      ++(*scmd);
      if (l_trailing(scmd, cmd) == FALSE)
      	return (FALSE);
    }
  else if (l_middle(scmd, cmd) == TRUE)
    {
      return (l_params(scmd, cmd));
    }
  else
    {
      remove_last_param(cmd);
      return (TRUE);
    }
  return (TRUE);
}
