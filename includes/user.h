/*
** user.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 19 19:55:04 2014 Jean Fauquenot
** Last update Mon Apr 21 18:40:36 2014 Gabriel Poulet de Grimouard
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
    FLAG_USER_NONE = 0b0000,
    FLAG_USER_IL = 0b0001,
    FLAG_USER_SL = 0b0010,
    FLAG_USER_WL = 0b0100,
    FLAG_USER_OL = 0b1000
  }			t_flags_user;

# define FLAG_USER_IL_STR	"i"
# define FLAG_USER_SL_STR	"s"
# define FLAG_USER_WL_STR	"w"
# define FLAG_USER_OL_STR	"o"

typedef struct		s_muser
{
  char			nick[USER_NICK_LEN];
  char			realname[USER_REALNAME_LEN];
  char			hostname[USER_HOSTNAME_LEN];
  t_chan		*chans;
  t_flags_user		mode;
  t_network		network;
}			t_muser;

typedef struct		s_user_l
{
  t_muser		data;
  struct s_user_l	*next;
}			t_user_l;

#endif /* !USER_H_ */
