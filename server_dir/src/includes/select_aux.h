/*
** select_aux.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 20:39:02 2014 Jean Fauquenot
** Last update Mon Apr 21 17:41:19 2014 Jean Fauquenot
*/

#ifndef SELECT_AUX_H_
# define SELECT_AUX_H_

#include	"core.h"
#include	"user.h"

typedef struct		s_select
{
  fd_set		readfds;
  fd_set		writefds;
  int			ndfs;
}			t_select;

void		set_select(t_select *, t_server *, t_user_l *);

#endif /* !SELECT_AUX_H_ */
