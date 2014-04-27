/*
** error_to_client.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 14:54:58 2014 Jean Fauquenot
** Last update Sun Apr 27 20:36:06 2014 Jean Fauquenot
*/

#include	"user.h"
#include	"command.h"

#include	<stdarg.h>
#include	<string.h>
#include	<stdio.h>

void error_to_client(t_duser *user, int id, char *msg, ...)
{
  va_list	ap;
  char		str[CMD_LEN + 1];

  va_start(ap, msg);
  vsnprintf(str, CMD_LEN + 1, msg, ap);
  va_end(ap);
  write_to_client(user, ":%s %d * %s\r\n", SERVER_NAME, id, str);
}

void message_to_client(t_duser *user, int id, char *msg, ...)
{
  va_list	ap;
  char		str[CMD_LEN + 1];

  va_start(ap, msg);
  vsnprintf(str, CMD_LEN + 1, msg, ap);
  va_end(ap);
  write_to_client(user, ":%s %d %s %s\r\n", SERVER_NAME, id, user->nick, str);
}
