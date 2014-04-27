/*
** send_message_channel.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 21:22:57 2014 Jean Fauquenot
** Last update Sun Apr 27 22:30:19 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

void		send_message_channel(t_irc *irc, t_duser *user,
				     char *name)
{
  t_chan	*chan;
  t_chan_user	*list;

  if ((chan = get_channel(name, irc->chans)) == NULL)
    {
      error_to_client(user, 401, "%s :No such channel", name);
      return ;
    }
  list = chan->users;
  while (list)
    {
      write_to_client(list->info, ":%s!%s@%s JOIN :%s\r\n",
		      user->nick,
		      user->username,
		      user->hostname,
		      name);
      list = list->next;
    }
}
