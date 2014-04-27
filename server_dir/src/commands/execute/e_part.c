/*
** e_part.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 22:04:31 2014 Jean Fauquenot
** Last update Sun Apr 27 23:30:21 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<stdlib.h>

void		remove_from_chan(t_chan *chan, t_duser *user)
{
  t_chan_user	*list;
  t_chan_user	*prev;

  prev = NULL;
  list = chan->users;
  while (list)
    {
      if (user == list->info)
	{
	  if (prev == NULL)
	    chan->users = list->next;
	  else
	    prev->next = list->next;
	  free(list);
	  return ;
	}
      list = list->next;
    }
}

void		remove_chan_if_empty(t_chan_l **root, t_chan *chan)
{
  t_chan_l	*prev;
  t_chan_l	*list;

  if (!chan || chan->users)
    return ;
  list = *root;
  prev = NULL;
  while (list)
    {
      if (chan == &list->data)
	{
	  if (prev == NULL)
	    *root = list->next;
	  else
	    prev->next = list->next;
	  free(list);
	}
      prev = list;
      list = list->next;
    }
}

static void	remove_chan_from_user(t_chan *chan, t_duser *user)
{
  size_t	i;

  i = 0;
  while (i < MAX_CHANNEL_BY_USER)
    {
      if (user->channel[i] == chan)
	user->channel[i] = NULL;
      ++i;
    }
}

t_state		e_part(t_irc *irc, t_duser *user, t_cmd *cmd)
{
  t_chan	*chan;

  if (user->identify == FALSE)
    return (SUCCESS);
  if ((chan = get_channel(cmd->params[0], irc->chans)) == NULL)
    return (SUCCESS);
  remove_from_chan(chan, user);
  remove_chan_from_user(chan, user);
  remove_chan_if_empty(&irc->chans, chan);
  return (SUCCESS);
}
