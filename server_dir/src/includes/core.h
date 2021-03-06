/*
** core.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 16:22:56 2014 Jean Fauquenot
** Last update Sun Apr 27 22:53:52 2014 Jean Fauquenot
*/

#ifndef CORE_H_
# define CORE_H_

# include	"usual.h"
# include	"network.h"
# include	"select_aux.h"

t_state		server(int, char **);

t_state		init_server(t_server *);

t_state		bind_server(t_server *);
t_state		listen_server(t_server *);
t_state		open_socket(t_server *);
t_state		init_protocol(t_server *);

void		destroy_server(t_server *);

t_state		select_loop(t_server *);

t_state		handle_fds(t_select *, t_server *, t_irc *);

t_state		server_fd(t_select *, t_server *, t_duser_l **);

t_state		add_client(t_server *, t_duser_l **);
t_state		remove_client(t_irc *, t_duser_l **, t_duser_l *);
t_state		destroy_clients_list(t_irc *, t_duser_l **);

t_state		handle_fds_clients(t_select *, t_server *, t_irc *);
t_state		handle_fds_clients_read(t_select *, t_server *, t_irc *);
t_state		handle_fds_clients_write(t_select *, t_server *,
					 t_duser_l **, t_irc *);

t_state		handle_fd_client_read(t_irc *, t_duser *);
t_state		handle_fd_client_write(t_duser *);

void		remove_from_chan(t_chan *, t_duser *);
void		remove_chan_if_empty(t_chan_l **, t_chan *);

#endif /* !CORE_H_ */
