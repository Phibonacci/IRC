/*
** remove_client.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 15:44:27 2014 Jean Fauquenot
** Last update Sun Apr 27 23:24:36 2014 Jean Fauquenot
*/

#include	"error.h"
#include	"chan.h"
#include	"user.h"
#include	"core.h"

#include	<unistd.h>
#include	<string.h>
#include	<errno.h>
#include	<stdlib.h>

static t_state	free_duser_l(t_duser_l *to_free)
{
  if (close(to_free->data.network.fd) == -1)
    return (merror("%s: %s", E_CLOSE, strerror(errno)));
  free(to_free);
  return (SUCCESS);
}

void		remove_client_chans(t_irc *irc, t_duser *user)
{
  size_t	i;

  i = 0;
  while (i < MAX_CHANNEL_BY_USER)
    {
      if (user->channel[i])
	{
	  remove_from_chan(user->channel[i], user);
	  remove_chan_if_empty(&irc->chans, user->channel[i]);
	}
      ++i;
    }
}

/*
** E_NOTINTLIST is not supposed to happen
** and is only there to help the programer.
*/
t_state		remove_client(t_irc *irc, t_duser_l **clist,
			      t_duser_l *to_free)
{
  t_duser_l	*it;

  remove_client_chans(irc, &to_free->data);
  it = *clist;
  while (it && it != to_free && it->next != to_free)
    it = it->next;
  if (!it)
    {
      merror("%s", E_NOTINLIST);
      return (SUCCESS);
    }
  else if (it == to_free)
    {
      *clist = (*clist)->next;
    }
  else if (it->next == to_free)
    it->next = it->next->next;
  return (free_duser_l(to_free));
}
