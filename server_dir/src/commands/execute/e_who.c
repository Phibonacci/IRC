/*
** e_who.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 21:35:28 2014 Jean Fauquenot
** Last update Sun Apr 27 22:02:37 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<stddef.h>

t_state		e_who(t_irc *irc, t_duser *user, t_cmd *cmd)
{
  t_chan	*chan;
  t_chan_user	*list;

  if (user->identify == FALSE)
    return (SUCCESS);
  if ((chan = get_channel(cmd->params[0], irc->chans)) == NULL)
    return (SUCCESS);
  list = chan->users;
  while (list)
    {
      message_to_client(user, 352, " %s %s %s %s %s :0 %s",
			chan->name,
			list->info->nick,
			list->info->username,
			list->info->realname,
			list->info->hostname,
			list->info->nick);
      list = list->next;
    }
  return (SUCCESS);
}
