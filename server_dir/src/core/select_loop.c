/*
** select_loop.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 20:26:47 2014 Jean Fauquenot
** Last update Tue Apr 22 13:27:59 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"
#include	"error.h"

#include	<sys/select.h>
#include	<errno.h>
#include	<string.h>
#include	<stdio.h>

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
  t_duser_l	*clist;

  clist = NULL;
  quit = FALSE;
  set_select(&settings, server, clist);
  while (!quit && (ret = select(settings.ndfs,
				&(settings.readfds),
				&(settings.writefds),
				NULL,
				NULL)) != -1)
    {
      if (handle_fds(&settings, server, &clist, &quit) == FAILURE)
	return (FAILURE);
      set_select(&settings, server, clist);
    }
  if (destroy_clients_list(&clist) == FAILURE)
    return (FAILURE);
  if (ret == -1)
    return (merror("%s: %s", E_SELECT, strerror(errno)));
  dprintf(2, "Exit with no error\n");
  return (SUCCESS);
}
