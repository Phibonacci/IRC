/*
** chan.c for chan in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir/src
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Tue Apr 22 17:53:13 2014 Gabriel Poulet de Grimouard
** Last update Sat Apr 26 16:44:35 2014 Gabriel Poulet de Grimouard
*/

#include <string.h>

#include "chan.h"
#include "client.h"
#include "user.h"

void		get_name_chan(char *msg, char into[CHAN_NAME_LEN])
{
  unsigned int	i;
  unsigned int	a;

  i = 0;
  while (msg[i] && msg[i] != '#')
    i++;
  a = i + 1;
  while (msg[a] && msg[a] != ' ' && msg[a] != '#' && msg[a] != '\r')
    a++;
  a = ((a - i) > CHAN_NAME_LEN ? CHAN_NAME_LEN : (a - i));
  strncpy(into, &msg[i], a);
  into[a] = '\0';
}

t_chan		*chan_new(char *msg)
{
  t_chan	*this;

  if (!(this = malloc(sizeof(*this))))
    exit(EXIT_FAILURE);
  this->mode = 0;
  get_name_chan(msg, this->name);
  this->buffer[0] = '\0';
  this->users = NULL;
  return (this);
}

void		add_chans(t_duser *user, t_client *client)
{
  unsigned int	i;
  char		into[CHAN_NAME_LEN];
  union u_val	val;

  i = strlen(client->cmd);
  into[0] = '1';
  while (into[0] != '\0')
    {
      get_name_chan(&client->msg[i], into);
      if (into[0] == '\0')
	continue ;
      val.ptr = chan_new(&into[0]);
      i += strlen(((t_chan*)val.ptr)->name);
      item_add_at_front(user->lchans, item_new_by_param(val, NULL, NULL));
    }
}

void		remove_chans(t_duser *user, t_client *client)
{
  char		chan[CHAN_NAME_LEN];
  unsigned int	i;
  t_item	*item;
  t_item	*save;

  chan[0] = '1';
  i = 0;
  while (chan[0] != '\0')
    {
      get_name_chan(&client->msg[i], chan);
      item = user->lchans->first;
      while (item)
	{
	  save = item;
	  if (!strcmp(((t_chan*)item->val.ptr)->name, chan))
	    item_remove(user->lchans, item);
	  item = save->next;
	}
      i += strlen(chan);
    }
}
