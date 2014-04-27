/*
** command.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 01:57:26 2014 Jean Fauquenot
** Last update Sun Apr 27 20:25:35 2014 Jean Fauquenot
*/

#ifndef COMMAND_H_
# define COMMAND_H_

# include	"user.h"
# include	"usual.h"

# include	<stdarg.h>

typedef struct		s_cmd
{
  char			*prefix;
  char			*command;
  char			*params[PARAMS_MAX + 1];
  t_state		(*exec)(t_irc *, t_duser *, struct s_cmd *);
}			t_cmd;

t_state		handle_command(t_irc *, t_duser *, char *);
void		write_to_client(t_duser *, char *, ...);
void		error_to_client(t_duser *, int, char *, ...);
void		message_to_client(t_duser *, int, char *, ...);

t_bool		command_lexer(char *, t_cmd *);
t_bool		command_parser(t_duser *, t_cmd *);
t_state		command_execute(t_irc *, t_duser *, t_cmd *);

#endif /* !COMMAND_H_ */
