/*
** write_to_client.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 13:31:31 2014 Jean Fauquenot
** Last update Sat Apr 26 14:56:44 2014 Jean Fauquenot
*/

#include	"user.h"

#include	<stdarg.h>
#include	<string.h>
#include	<stdio.h>

static int	find_empty_str(char *buffer)
{
  int		i;

  i = 0;
  while (CMD_STORED > i)
    {
      if (buffer[i * (CMD_LEN + 1)] == 0)
	return (i);
      ++i;
    }
  return (-1);
}

static void	do_a_barrel_roll(char *buffer, char *msg)
{
  memmove(buffer, buffer + (CMD_LEN + 1), CMD_LEN + 1);
  bzero(buffer + USER_BUFFER - (CMD_LEN + 1), CMD_LEN + 1);
  strcpy(buffer + USER_BUFFER - (CMD_LEN + 1), msg);
}

static void	add_msg(char *buffer, char *msg)
{
  int		pos;

  pos = find_empty_str(buffer);
  if (pos == -1)
    do_a_barrel_roll(buffer, msg);
  else
    strcpy(buffer + (pos * (CMD_LEN + 1)), msg);
}

void		write_to_client(t_duser *user, char *msg, ...)
{
  va_list	ap;
  char		str[CMD_LEN + 1];

  va_start(ap, msg);
  vsprintf(str, msg, ap);
  va_end(ap);
  add_msg(&(user->buffer[0]), str);
}
