/*
** select_loop.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 20:26:47 2014 Jean Fauquenot
** Last update Sun Apr 27 22:39:24 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"
#include	"error.h"

#include	<sys/select.h>
#include	<errno.h>
#include	<string.h>
#include	<stdio.h>

void		init_loop(t_bool *quit, t_duser_l **users, t_chan_l **chans)
{
  *chans = NULL;
  *users = NULL;
  *quit = FALSE;
}

/**
** Loop any time a file descriptor is up.
** @param server a t_server argument.
** @return The t_state state of the function.
*/
t_state		select_loop(t_server *server)
{
  int		ret;
  t_select	settings;
  t_irc		irc;

  init_loop(&irc.quit, &irc.users, &irc.chans);
  set_select(&settings, server, irc.users);
  while (!irc.quit && (ret = select(settings.ndfs,
				&(settings.readfds),
				&(settings.writefds),
				NULL,
				NULL)) != -1)
    {
      if (handle_fds(&settings, server, &irc) == FAILURE)
	return (FAILURE);
      set_select(&settings, server, irc.users);
    }
  if (destroy_clients_list(&irc, &irc.users) == FAILURE)
    return (FAILURE);
  if (ret == -1)
    return (merror("%s: %s", E_SELECT, strerror(errno)));
  dprintf(2, "Exit with no error\n");
  return (SUCCESS);
}
