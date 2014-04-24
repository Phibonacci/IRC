/*
** destroy_duser_l.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 20:03:50 2014 Jean Fauquenot
** Last update Tue Apr 22 16:36:03 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"usual.h"

#include	<stdio.h>

/**
** Free all the user information and disconnect the users.
** @param clist a t_duser_l list of user.
** @return The t_state state of the function.
*/
t_state		destroy_clients_list(t_duser_l **clist)
{
  t_duser_l	*it;
  t_duser_l	*to_free;
  t_state	ret;

  dprintf(2, "Cleaning memory\n");
  it = *clist;
  ret = SUCCESS;
  while (it)
    {
      to_free = it;
      it = it->next;
      if (remove_client(clist, to_free) == FAILURE)
	ret = FAILURE;
    }
  return (ret);
}
