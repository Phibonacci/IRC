/*
** user.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Mon Apr 21 19:44:08 2014 Jean Fauquenot
** Last update Thu Apr 24 18:20:44 2014 Jean Fauquenot
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

typedef struct		s_duser
{
  char			nick[USER_NICK_LEN + 1];
  char			username[USER_USERNAME_LEN + 1];
  char			realname[USER_REALNAME_LEN + 1];
  char			hostname[USER_HOSTNAME_LEN + 1];
  t_chan		*chans;
  t_flags_user		mode;
  t_network		network;
  char			buffer[USER_BUFFER];
}			t_duser;

typedef struct		s_duser_l
{
  t_duser		data;
  struct s_duser_l	*next;
}			t_duser_l;

#endif /* !USER_H_ */
