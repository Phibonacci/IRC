/*
** execute.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 17:16:13 2014 Jean Fauquenot
** Last update Thu Apr 24 20:57:57 2014 Jean Fauquenot
*/

#ifndef EXECUTE_H_
# define EXECUTE_H_

# include	"user.h"
# include	"command.h"

# define RPL_WELCOME	"Welcome to the Internet Relay Network"

t_bool		e_nick(t_duser *, t_cmd *);
t_bool		e_user(t_duser *, t_cmd *);
t_bool		e_mode(t_duser *, t_cmd *);
t_bool		e_whois(t_duser *, t_cmd *);
t_bool		e_ping(t_duser *, t_cmd *);

#endif /* !EXECUTE_H_ */
