/*
** network.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 16:12:01 2014 Jean Fauquenot
** Last update Thu Apr 17 16:56:56 2014 Jean Fauquenot
*/

#ifndef NETWORK_H_
# define NETWORK_H_

# include	<netdb.h>

typedef struct		s_network
{
  int			fd;
  struct sockaddr_in	addr;
  socklen_t		slen;
  int			port;
  char			*ip;
}			t_network;

typedef struct		s_server
{
  struct protoent	*protocol;
  t_network		network;
}			t_server;

#endif /* !NETWORK_H_ */
