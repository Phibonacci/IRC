/*
** handle_fd_client_read.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 23:28:18 2014 Jean Fauquenot
** Last update Thu Apr 24 13:53:46 2014 Jean Fauquenot
*/

#include	"user.h"
#include	"usual.h"
#include	"error.h"
#include	"command.h"

#include	<unistd.h>
#include	<errno.h>
#include	<string.h>

static t_bool	find_new_cmd(char **new_cmd)
{
  while (**new_cmd != '\0' && **new_cmd != '\n')
    {
      ++(*new_cmd);
    }
  if (**new_cmd == '\0')
    return (FALSE);
  ++(*new_cmd);
  if (**new_cmd == '\0')
    return (FALSE);
  return (TRUE);
}

t_state		handle_fd_client_read(t_duser *user)
{
  char		cmd[CMD_LEN + 1];
  int		ret;
  t_state	state;
  char		*new_cmd;
  char		*prev_cmd;
  t_bool	loop;

  if ((ret = read(user->network.fd, cmd, CMD_LEN)) > 0)
    {
      cmd[ret] = 0;
      new_cmd = &(cmd[0]);
      loop = TRUE;
      while (loop == TRUE)
	{
	  prev_cmd = new_cmd;
	  loop = find_new_cmd(&new_cmd);
	  if ((state = handle_command(user, prev_cmd)) != SUCCESS)
	    return (state);
	}
    }
  else
    {
      merror("%s: %s", E_RECV, strerror(errno));
      return (FAILURE_L1);
    }
  return (SUCCESS);
}
