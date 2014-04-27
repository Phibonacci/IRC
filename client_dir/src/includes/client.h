/*
** client.h for client in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir/
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 14:45:58 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 21:09:55 2014 Gabriel Poulet de Grimouard
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <sys/select.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# include "usual.h"
# include "network.h"

struct s_duser;
struct s_chan;
typedef uint32_t	in_addr_t;

typedef struct		s_fxchg
{
  char			fname[50];
  char			nicksend[16];
  int			fd;
  int			is_inuse : 1;
  t_bool		readd : 1;
  in_addr_t		ip;
  int			port;
}			t_fxchg;

typedef struct		s_client
{
  char			msg[512 + 1];
  t_fxchg		fxchg;
  char			*cmd;
  in_addr_t		ip;
  int			len_msg;
  int			port;
  fd_set		fd_write;
  t_bool		towrite : 1;
  t_bool		quit : 1;
}			t_client;

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

void		get_ip_port(char *msg, int *port, char **ip);
t_state		set_ip_port(t_client *client, struct s_duser *user);
t_state		write_to_serv(t_client *client, struct s_duser *user);
void		client_init(t_client *client);
struct s_duser	*user_create(void);
int		parse_cmd(t_client *client);
struct s_chan	*chan_new(char *msg);
void		add_chans(struct s_duser *user, t_client *client);
void		remove_chans(struct s_duser *user, t_client *client);
void		user_cmd(struct s_duser *user);
t_state		user_join_cmd(t_client *, struct s_duser *);
t_state		user_serv_cmd(t_client *, struct s_duser *);
t_state		user_nick_cmd(t_client *, struct s_duser *);
t_state		user_list_cmd(t_client *, struct s_duser *);
t_state		user_part_cmd(t_client *, struct s_duser *);
t_state		user_user_cmd(t_client *, struct s_duser *);
t_state		user_privmsg_cmd(t_client *, struct s_duser *);
t_state		user_send_cmd(t_client *, struct s_duser *);
t_state		user_accept_cmd(t_client *, struct s_duser *);
t_state		user_msg_cmd(t_client *, struct s_duser *);
t_state		user_quit_cmd(t_client *, struct s_duser *);
int		user_connect_to_srv(t_network *net,
				    int port, in_addr_t ip);
t_state		read_cmd(t_client *client, struct s_duser *user);

#endif /* !CLIENT_H_ */
