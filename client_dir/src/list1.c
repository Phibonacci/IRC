/*
** list1.c for list1 in /home/poulet_g/projet/lib
**
** Made by gabriel poulet-de-grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Tue Jan  7 16:39:01 2014 gabriel poulet-de-grimouard
** Last update Fri Apr 11 17:26:30 2014 Gabriel Poulet de Grimouard
*/

#include <stdlib.h>

#include "chainlist.h"

t_list		*list_new(void)
{
  t_list	*this;

  if (!(this = (t_list*)malloc(sizeof(*this))))
    exit(EXIT_FAILURE);
  this->first = NULL;
  this->end = NULL;
  this->count = 0;
  return (this);
}

void		item_init_by_default(t_item *this)
{
  this->val.ival = 0;
  this->next = NULL;
  this->prev = NULL;
}

void		item_init_by_param(t_item *this, union u_val val,
				   t_item *next, t_item *prev)
{
  this->val = val;
  this->next = next;
  this->prev = prev;
}

void		item_add_at_front(t_list *this, t_item *item)
{
  if (this)
    {
      item->next = this->first;
      if (this->first)
	this->first->prev = item;
      this->first = item;
      if (this->end == NULL)
	this->end = item;
      this->count++;
    }
}

void		item_add_at_back(t_list *this, t_item *item)
{
  if (this)
    {
      if (this->first == NULL)
	this->first = item;
      if (this->end)
	this->end->next = item;
      item->prev = this->end;
      this->end = item;
      this->count++;
    }
}
