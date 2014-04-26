/*
** parser.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 24 14:05:26 2014 Jean Fauquenot
** Last update Thu Apr 24 17:27:09 2014 Jean Fauquenot
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
  t_bool		(*exec)(t_duser *, t_cmd *);
}			t_parser_cmd;

#endif /* !PARSER_H_ */
