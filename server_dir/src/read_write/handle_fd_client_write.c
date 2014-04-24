/*
** handle_fd_client_write.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 03:20:16 2014 Jean Fauquenot
** Last update Tue Apr 22 16:30:14 2014 Jean Fauquenot
*/

#include	"user.h"
#include	"usual.h"
#include	"error.h"
#include	"command.h"

#include	<unistd.h>
#include	<errno.h>
#include	<string.h>

static void	move_buffer_user(char *buffer)
{
  memmove(buffer, buffer + (CMD_LEN + 1), (USER_BUFFER - CMD_LEN + 1));
  bzero(buffer + USER_BUFFER - (CMD_LEN + 1), (CMD_LEN + 1));
}

t_state		handle_fd_client_write(t_duser *user)
{
  int		ret;
  int		len;

  if (user->buffer[0])
    {
      len = strlen(user->buffer);
      ret = write(user->network.fd, user->buffer, len);
      if (ret != len)
	{
	  merror("%s: %s\n", E_RECV, strerror(errno));
	  return (FAILURE_L1);
	}
      move_buffer_user(&(user->buffer[0]));
    }
  return (SUCCESS);
}
