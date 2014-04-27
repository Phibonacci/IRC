/*
** e_join.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 15:32:40 2014 Jean Fauquenot
** Last update Sun Apr 27 21:22:48 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

t_chan	*get_channel(char *name, t_chan_l *list)
{
  while (list)
    {
      if (strcmp(name, list->data.name) == 0)
	return (&list->data);
      list = list->next;
    }
  return (NULL);
}

/*
**  ERR_NEEDMOREPARAMS            ERR_BANNEDFROMCHAN
**  ERR_INVITEONLYCHAN            ERR_BADCHANNELKEY
**  ERR_CHANNELISFULL             ERR_BADCHANMASK
**  ERR_NOSUCHCHANNEL             ERR_TOOMANYCHANNELS
**  RPL_TOPIC
*/
static t_state	join_chan(char *param, t_irc *irc, t_duser *user)
{
  t_chan	*chan;
  t_chan_l	*new;

  if (invalid_join(param, user) != SUCCESS)
    return (SUCCESS);
  if ((chan = get_channel(param, irc->chans)) == NULL)
    {
      if ((new = new_chan(param)) == NULL)
	return (FAILURE);
      if (add_chans_to_list(&irc->chans, new) == FAILURE)
	return (FAILURE);
      chan = &new->data;
    }
  if (add_user_to_chan(chan, user) == FAILURE)
    return (FAILURE);
  send_message_channel(irc, user, param);
  return (SUCCESS);
}

static t_state	add_chans_to_arg_chans(char *params,
				       t_irc *irc,
				       t_duser *user)
{
  char		*param;

  while ((param = strtok(params, ",")))
    {
      if (join_chan(param, irc, user) == FAILURE)
	return (FAILURE);
      params = NULL;
    }
  return (SUCCESS);
}

t_state		e_join(t_irc *irc, t_duser *user, t_cmd *cmd)
{
  if (user->identify == FALSE)
    return (SUCCESS);
  if (add_chans_to_arg_chans(cmd->params[0], irc, user) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
