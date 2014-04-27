/*
** add_chans_to_list.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 13:12:02 2014 Jean Fauquenot
** Last update Sun Apr 27 14:13:28 2014 Jean Fauquenot
*/

#include	"chan.h"

t_state add_chans_to_list(t_chan_l **list, t_chan_l *chan)
{
  t_chan_l *it;

  it = *list;
  while (it && it->next)
    it = it->next;
  if (!it)
    *list = chan;
  else
    it->next = chan;
  return (SUCCESS);
}
