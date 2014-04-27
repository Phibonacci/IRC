/*
** parser.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 14:05:26 2014 Jean Fauquenot
** Last update Sun Apr 27 22:07:16 2014 Jean Fauquenot
*/

#ifndef PARSER_H_
# define PARSER_H_

# include	"user.h"
# include	"command.h"
# include	"usual.h"

typedef struct		s_parser_cmd
{
  size_t		index;
  char			*name;
  t_state		(*exec)(t_irc *, t_duser *, t_cmd *);
  t_bool		(*parse)(t_cmd *);
}			t_parser_cmd;

t_bool		p_nick(t_cmd *);
t_bool		p_user(t_cmd *);
t_bool		p_mode(t_cmd *);
t_bool		p_whois(t_cmd *);
t_bool		p_ping(t_cmd *);
t_bool		p_join(t_cmd *);
t_bool		p_privmsg(t_cmd *);
t_bool		p_list(t_cmd *);
t_bool		p_who(t_cmd *);
t_bool		p_part(t_cmd *);

#endif /* !PARSER_H_ */
