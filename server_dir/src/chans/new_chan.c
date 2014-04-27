/*
** new_chan.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 13:12:15 2014 Jean Fauquenot
** Last update Sun Apr 27 16:37:39 2014 Jean Fauquenot
*/

#include	"chan.h"

#include	<stdlib.h>
#include	<string.h>

static void	init_new(t_chan *chan, char *name)
{
  memset(chan, 0, sizeof(*chan));
  strncpy(chan->name, name, CHAN_NAME_LEN);
  chan->mode |= FLAG_CHAN_SL | FLAG_CHAN_NL;
}

t_chan_l	*new_chan(char *name)
{
  t_chan_l	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->next = NULL;
  init_new(&new->data, name);
  return (new);
}
