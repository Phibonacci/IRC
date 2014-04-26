/*
** lexer.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 17:46:31 2014 Jean Fauquenot
** Last update Wed Apr 23 12:35:45 2014 Jean Fauquenot
*/

#ifndef LEXER_H_
# define LEXER_H_

# include	"command.h"

/*
** Level1
*/
t_bool		l_message(char **, t_cmd *);

/*
** Level2
*/
t_bool		l_prefix(char **, t_cmd *);
t_bool		l_space(char **, t_cmd *);
t_bool		l_command(char **, t_cmd *);
t_bool		l_params(char **, t_cmd *);
t_bool		l_crlf(char **, t_cmd *);

/*
** Level3
*/
t_bool		l_middle(char **, t_cmd *);
t_bool		l_trailing(char **, t_cmd *);

/*
** Level4
*/
t_bool		l_letter(char **, t_cmd *);
t_bool		l_number(char **, t_cmd *);

t_bool		match_char_of_string(char, char const *);

#endif /* !LEXER_H_ */
