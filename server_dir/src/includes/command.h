/*
** command.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 01:57:26 2014 Jean Fauquenot
** Last update Thu Apr 24 17:24:14 2014 Jean Fauquenot
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
  t_bool		(*exec)(t_duser *, struct s_cmd *);
}			t_cmd;

t_state		handle_command(t_duser *, char *);
void		write_to_client(t_duser *, char *, ...);

t_bool		command_lexer(char *, t_cmd *);
t_bool		command_parser(t_duser *, t_cmd *);
t_bool		command_execute(t_duser *, t_cmd *);

#endif /* !COMMAND_H_ */
