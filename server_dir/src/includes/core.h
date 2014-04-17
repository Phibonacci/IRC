/*
** core.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 16:22:56 2014 Jean Fauquenot
** Last update Thu Apr 17 20:28:04 2014 Jean Fauquenot
*/

#ifndef CORE_H_
# define CORE_H_

# include	"usual.h"
# include	"network.h"

t_state		server(int, char **);

t_state		init_server(t_server *);

t_state		bind_server(t_server *);
t_state		listen_server(t_server *);
t_state		open_socket(t_server *);
t_state		init_protocol(t_server *);

void		destroy_server(t_server *);

t_state		select_loop(t_server *);

#endif /* !CORE_H_ */
