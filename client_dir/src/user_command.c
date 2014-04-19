/*
** user_command.c for user_cnd in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:41:59 2014 Gabriel Poulet de Grimouard
** Last update Fri Apr 18 18:58:09 2014 Gabriel Poulet de Grimouard
*/

#include <unistd.h>

#include "client.h"
#include "user.h"

void			user_cmd(t_user *user)
{
  t_client	client;

  client_init(&client);
  (void)user;
  while (client.quit == FALSE)
    {
      if ((client.len_msg = read(0, client.msg, 510)) <= 0)
	return ;
      client.msg[client.len_msg] = '\r';
      client.msg[client.len_msg + 1] = '\0';
      parse_cmd(&client);
    }
}
