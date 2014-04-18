/*
** user.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 14:19:11 2014 Jean Fauquenot
** Last update Fri Apr 18 14:48:33 2014 Gabriel Poulet de Grimouard
*/

#ifndef USER_H_
# define USER_H_

# include	"setvalues.h"
# include	"network.h"
# include	"chan.h"

/*
** FLAG_<name><case>
** <name> : name of the flag (i.e.: I)
** <case> : lower (L) or upper (U) case
**
** Parameters: <nickname> {[+|-]|i|w|s|o}
**  i - marks a users as invisible;
**  s - marks a user for receipt of server notices;
**  w - user receives wallops;
**  o - operator flag.
*/
typedef enum		e_flags_user
  {
    FLAG_USER_IL = 0b0001,
    FLAG_USER_SL = 0b0010,
    FLAG_USER_WL = 0b0100,
    FLAG_USER_OL = 0b1000
  }			t_flags_user;

# define FLAG_USER_IL_STR	"i"
# define FLAG_USER_SL_STR	"s"
# define FLAG_USER_WL_STR	"w"
# define FLAG_USER_OL_STR	"o"

typedef struct		s_user
{
  char			nick[USER_NICK_LEN];
  char			realname[USER_REALNAME_LEN];
  char			hostname[USER_HOSTNAME_LEN];
  t_chan		*chans;
  t_flags_user		mode;
  t_network		network;
}			t_user;

typedef struct		s_user_l
{
  t_user		data;
  struct s_user_l	*next;
}			t_user_l;

#endif /* !USER_H_ */
