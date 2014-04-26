/*
** list2.c for list in /home/drdrak/rendu/unix/PSU_2013_myftp
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Thu Apr 10 18:57:11 2014 Gabriel Poulet de Grimouard
** Last update Fri Apr 11 17:35:37 2014 Gabriel Poulet de Grimouard
*/

#include <stdlib.h>

#include "chainlist.h"

t_item		*item_new_by_default(void)
{
  t_item	*item;

  if (!(item = malloc(sizeof(*item))))
    exit(EXIT_FAILURE);
  item->val.ival = 0;
  item->next = NULL;
  item->prev = NULL;
  return (item);
}

t_item		*item_new_by_param(union u_val val, t_item *next, t_item *prev)
{
  t_item	*item;

  if (!(item = malloc(sizeof(*item))))
    exit(EXIT_FAILURE);
  item->val = val;
  item->next = next;
  item->prev = prev;
  return (item);
}

void		item_remove(t_list *this, t_item *item)
{
  t_item	*check;

  if (this && item)
    {
      check = this->first;
      while (check && check != item)
	check = check->next;
      if (!check)
	return ;
      if (check->prev)
	check->prev->next = check->next;
      if (check->next)
	check->next->prev = check->prev;
      if (check == this->first)
	this->first = check->next;
      if (check == this->end)
	this->end = check->prev;
      free(check);
      --this->count;
      if (this->count == 0)
	{
	  this->first = NULL;
	  this->end = NULL;
	}
    }
}
