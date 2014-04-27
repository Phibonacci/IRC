/*
** execute.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 17:16:13 2014 Jean Fauquenot
** Last update Sun Apr 27 22:07:34 2014 Jean Fauquenot
*/

#ifndef EXECUTE_H_
# define EXECUTE_H_

# include	"user.h"
# include	"command.h"

# define RPL_WELCOME	"Welcome to irc.mrphi.net !"

t_state		e_nick(t_irc *, t_duser *, t_cmd *);
t_state		e_user(t_irc *, t_duser *, t_cmd *);
t_state		e_mode(t_irc *, t_duser *, t_cmd *);
t_state		e_whois(t_irc *, t_duser *, t_cmd *);
t_state		e_ping(t_irc *, t_duser *, t_cmd *);
t_state		e_join(t_irc *, t_duser *, t_cmd *);
t_state		invalid_join(char *, t_duser *);
t_state		e_privmsg(t_irc *, t_duser *, t_cmd *);
t_state		e_list(t_irc *, t_duser *, t_cmd *);
void		send_message_channel(t_irc *, t_duser *, char *);
t_state		e_who(t_irc *, t_duser *, t_cmd *);
t_state		e_part(t_irc *, t_duser *, t_cmd *);

int		array_chan_len(t_duser *);
t_chan		*get_channel(char *, t_chan_l *);

#endif /* !EXECUTE_H_ */
