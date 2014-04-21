/*
** core.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 16:22:56 2014 Jean Fauquenot
** Last update Mon Apr 21 18:58:22 2014 Jean Fauquenot
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

t_state		handle_fds(t_select *, t_server *, t_duser_l **);

t_state		server_fd(t_select *, t_server *, t_duser_l **);

t_state		add_client(t_server *, t_duser_l **);
t_state		remove_client(t_duser_l **, t_duser_l *);

t_state		handle_fds_clients(t_select *, t_server *, t_duser_l **);
t_state		handle_fds_clients_read(t_select *, t_server *, t_duser_l **);
t_state		handle_fds_clients_write(t_select *, t_server *, t_duser_l **);

#endif /* !CORE_H_ */
