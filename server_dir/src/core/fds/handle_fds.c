/*
** handle_fds.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Fri Apr 18 12:52:49 2014 Jean Fauquenot
** Last update Sun Apr 27 11:14:42 2014 Jean Fauquenot
*/

#include	"core.h"
#include	"select_aux.h"
#include	"user.h"
#include	"error.h"

#include	<errno.h>
#include	<string.h>
#include	<unistd.h>

static t_state	read_stdin(t_bool *quit)
{
  char		buff[CMD_LEN + 1];
  int		ret;

  if ((ret = read(0, buff, CMD_LEN)) > 0)
    {
      buff[ret] = 0;
      if (strcmp(buff, "quit\n") == 0)
	*quit = TRUE;
    }
  else if (ret == 0)
    *quit = TRUE;
  else if (ret == -1)
    return (merror("%s: %s", E_READ, strerror(errno)));
  return (SUCCESS);
}

t_state		handle_fds(t_select *settings,
			   t_server *server,
			   t_irc *irc)
{
  t_state	ret;

  if (FD_ISSET(0, &settings->readfds))
    if (read_stdin(&irc->quit) == FAILURE)
      return (FAILURE);
  if ((ret = server_fd(settings, server, &irc->users)) == FAILURE)
    return (FAILURE);
  if ((ret = handle_fds_clients(settings, server, irc)) == FAILURE)
    return (FAILURE);
  return (SUCCESS);
}
