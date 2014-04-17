/*
** select_loop.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 20:26:47 2014 Jean Fauquenot
** Last update Thu Apr 17 21:39:37 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"
#include	"error.h"

#include	<sys/select.h>
#include	<errno.h>
#include	<string.h>

/**
** Loop any time a file descriptor is up.
** @param server a t_server argument.
** @return The t_state state of the function.
*/
t_state		select_loop(t_server *server)
{
  t_bool	quit;
  int		ret;
  t_select	settings;
  t_user_l	*clist;

  clist = NULL;
  quit = FALSE;
  set_select(&settings, server, clist);
  while (!quit && (ret = select(settings.ndfs,
				&settings.readfds,
				&settings.writefds,
				NULL,
				NULL)) != -1)
    {
      set_select(&settings, server, clist);
    }
  if (ret == -1)
    {
      return (error("%s: %s", E_SELECT, strerror(errno)));
    }
  return (SUCCESS);
}
