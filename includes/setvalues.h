/*
** setvalues.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 23:20:35 2014 Jean Fauquenot
** Last update Sun Apr 27 23:20:36 2014 Jean Fauquenot
*/

#ifndef SETVALUES_H_
# define SETVALUES_H_

# define NB_MSG			10
/*
** RFC1459 2.3
*/
# define CMD_LEN		512
# define PARAMS_MAX		15

# define CHAN_TOPIC_LEN		390
# define CHAN_NAME_LEN		200
# define CHAN_KEY_LEN		50

# define MAX_CHANNEL_BY_USER	10

/*
** Upgraded from 9 to 16 by a new rfc
*/
# define USER_NICK_LEN		16

# define USER_USERNAME_LEN	10
# define USER_REALNAME_LEN	32
# define USER_HOSTNAME_LEN	32

# define CMD_STORED		20
# define USER_BUFFER		((CMD_LEN + 1) * CMD_STORED)

# define SERVER_NAME		"irc.mrphi.net"

#endif /* !SETVALUES_H_ */
