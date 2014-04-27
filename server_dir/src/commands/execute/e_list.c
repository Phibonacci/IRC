/*
** e_list.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 19:36:23 2014 Jean Fauquenot
** Last update Sun Apr 27 23:37:54 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

int		user_on_chan(t_chan_user *list)
{
  int		len;

  len = 0;
  while (list)
    {
      ++len;
      list = list->next;
    }
  return (len);
}

t_state		e_list(t_irc *irc, t_duser *user, t_cmd *cmd)
{
  t_chan_l	*list;

  if (!irc->chans)
    return (SUCCESS);
  list = irc->chans;
  if (user->identify == FALSE)
    return (SUCCESS);
  while (list)
    {
      if (!cmd->params[0] || strstr(list->data.name, cmd->params[0]) != NULL)
	message_to_client(user, 322, "%s %d :%s",
			  list->data.name,
			  user_on_chan(list->data.users),
			  list->data.topic);
      list = list->next;
    }
  return (SUCCESS);
}
