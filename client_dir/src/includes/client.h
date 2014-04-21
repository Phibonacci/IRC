/*
** client.h for client in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir/
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:45:58 2014 Gabriel Poulet de Grimouard
** Last update Mon Apr 21 18:42:02 2014 Gabriel Poulet de Grimouard
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include "usual.h"

struct s_muser;

typedef struct	s_client
{
  char		msg[512 + 1];
  char		*cmd;
  int		len_msg;
  t_bool	quit : 1;
}		t_client;

typedef struct	s_cmd
{
  char		cmd[50];
  char		trad[50];
  char		shr_cmd[4];
}		t_cmd;

typedef struct	s_fnct
{
  char		*cmd;
  t_state	(*fnct)();
}		t_fnct;

void		client_init(t_client *client);
struct s_muser	*user_create(void);
int		parse_cmd(t_client *client);
void		user_cmd(struct s_muser *user);
t_state		user_join_cmd(t_client *, struct s_muser *);
t_state		user_serv_cmd(t_client *, struct s_muser *);
t_state		user_nick_cmd(t_client *, struct s_muser *);
t_state		user_list_cmd(t_client *, struct s_muser *);
t_state		user_part_cmd(t_client *, struct s_muser *);
t_state		user_user_cmd(t_client *, struct s_muser *);
t_state		user_privmsg_cmd(t_client *, struct s_muser *);
t_state		user_send_cmd(t_client *, struct s_muser *);
t_state		user_accept_cmd(t_client *, struct s_muser *);
t_state		user_msg_cmd(t_client *, struct s_muser *);

#endif /* !CLIENT_H_ */
