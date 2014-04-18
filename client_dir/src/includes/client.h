/*
** client.h for client in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir/
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:45:58 2014 Gabriel Poulet de Grimouard
** Last update Fri Apr 18 19:42:32 2014 Gabriel Poulet de Grimouard
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "usual.h"

struct s_user;

typedef struct	s_client
{
  char		msg[512 + 1];
  int		len_msg;
  t_bool	quit : 1;
}		t_client;

typedef struct	s_cmd
{
  char		shr_cmd[3];
  char		cmd[50];
  char		trad[10];
}		t_cmd;

void		client_init(t_client *client);
struct s_user	*user_create(void);
int		parse_cmd(t_client *client);

#endif /* !CLIENT_H_ */
