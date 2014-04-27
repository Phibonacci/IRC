/*
** add_user_to_chan.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 15:43:49 2014 Jean Fauquenot
** Last update Sun Apr 27 20:49:03 2014 Jean Fauquenot
*/

#include	"user.h"
#include	"chan.h"

#include	<stdlib.h>

int		array_chan_len(t_duser *user)
{
  size_t	i;

  i = 0;
  while (user->channel[i] != NULL)
    ++i;
  return (i);
}

static t_state	add_chan_to_user(t_chan *chan, t_duser *user)
{
  size_t	i;

  i = 0;
  while (user->channel[i] != NULL)
    ++i;
  user->channel[i] = chan;
  return (SUCCESS);
}

t_state		add_user_to_chan_list(t_chan *chan, t_chan_user *new)
{
  t_chan_user	*it;

  it = chan->users;
  while (it && it->next)
    it = it->next;
  if (chan->users == NULL)
    chan->users = new;
  else
    it->next = new;
  return (SUCCESS);
}

t_state		add_user_to_chan_aux(t_chan *chan, t_duser *user)
{
  t_chan_user	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (FAILURE);
  new->mode = 0;
  new->info = user;
  new->next = NULL;
  add_user_to_chan_list(chan, new);
  return (SUCCESS);
}

t_state		add_user_to_chan(t_chan *chan, t_duser *user)
{
  if (add_chan_to_user(chan, user) == FAILURE)
    return (FAILURE);
  if (add_user_to_chan_aux(chan, user) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
