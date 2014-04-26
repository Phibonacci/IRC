/*
** remove_client.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 15:44:27 2014 Jean Fauquenot
** Last update Thu Apr 24 11:47:49 2014 Jean Fauquenot
*/

#include	"error.h"
#include	"chan.h"
#include	"user.h"

#include	<unistd.h>
#include	<string.h>
#include	<errno.h>

/*
** if alone on chan → delete chan
*/
static t_state	free_chans(t_chan *chans)
{
  (void)chans;
  return (SUCCESS);
}

static t_state	free_duser_l(t_duser_l *to_free)
{
  if (close(to_free->data.network.fd) == -1)
    return (merror("%s: %s", E_CLOSE, strerror(errno)));
  free_chans(to_free->data.chans);
  free(to_free);
  return (SUCCESS);
}

/*
** E_NOTINTLIST is not supposed to happen
** and is only there to help the programer.
*/
t_state		remove_client(t_duser_l **clist, t_duser_l *to_free)
{
  t_duser_l	*it;

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
