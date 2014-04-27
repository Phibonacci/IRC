/*
** e_privmsg.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 17:58:59 2014 Jean Fauquenot
** Last update Sun Apr 27 19:16:15 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

t_duser		*get_user(t_duser_l *list, char *name)
{
  while (list)
    {
      if (strcmp(name, list->data.nick) == 0)
	  return (&list->data);
      list = list->next;
    }
  return (NULL);
}

void		send_to_user(t_irc *irc, t_duser *user,
			     char *name, char *msg)
{
  t_duser	*send_user;

  if ((send_user = get_user(irc->users, name)) == NULL)
    {
      error_to_client(user, 401, "%s :No such nick", name);
      return ;
    }
  write_to_client(send_user,
		  ":%s!%s@%s PRIVMSG %s :%s\r\n",
		  user->nick,
		  user->username, user->hostname,
		  name,
		  msg + 1);
}

void		send_to_channel(t_irc *irc, t_duser *user,
				char *name, char *msg)
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
      if (strcmp(list->info->nick, user->nick))
	write_to_client(list->info,
			":%s!%s@%s PRIVMSG %s :%s\r\n",
			user->nick,
			user->username, user->hostname,
			name,
			msg + 1);
      list = list->next;
    }
}

t_state		e_privmsg(t_irc *irc, t_duser *user, t_cmd *cmd)
{
  if (!cmd->params[0])
    return (SUCCESS);
  if (cmd->params[0][0] != '#' && cmd->params[0][0] != '&')
    send_to_user(irc, user, cmd->params[0], cmd->params[1]);
  else
    send_to_channel(irc, user, cmd->params[0], cmd->params[1]);
  return (SUCCESS);
}
