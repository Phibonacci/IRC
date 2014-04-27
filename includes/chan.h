/*
** chan.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Wed Apr 16 17:04:57 2014 Jean Fauquenot
** Last update Sun Apr 27 15:52:29 2014 Jean Fauquenot
*/

#ifndef CHAN_H_
# define CHAN_H_

# include	"setvalues.h"
# include	"usual.h"

# include	<stdint.h>

/*
** FLAG_<name><case>
** <name> : name of the flag (i.e.: I)
** <case> : lower (L) or upper (U) case
**
** Parameters: <channel> {[+|-]|o|p|s|i|t|n|b|v} [<limit>] [<user>]
**  o - give/take channel operator privileges;
**  p - private channel flag;
**  s - secret channel flag;
**  i - invite-only channel flag;
**  t - topic settable by channel operator only flag;
**  n - no messages to channel from clients on the outside;
**  m - moderated channel;
**  l - set the user limit to channel;
**  b - set a ban mask to keep users out;
**  v - give/take the ability to speak on a moderated channel;
**  k - set a channel key (password).
*/
typedef enum		e_flags_chan
  {
    FLAG_CHAN_PL = 0b000001,
    FLAG_CHAN_SL = 0b000010,
    FLAG_CHAN_IL = 0b000100,
    FLAG_CHAN_TL = 0b001000,
    FLAG_CHAN_NL = 0b010000,
    FLAG_CHAN_ML = 0b100000
  }			t_flags_chan;

# define FLAG_CHAN_PL_STR	"p"
# define FLAG_CHAN_SL_STR	"s"
# define FLAG_CHAN_IL_STR	"i"
# define FLAG_CHAN_TL_STR	"t"
# define FLAG_CHAN_NL_STR	"n"
# define FLAG_CHAN_ML_STR	"m"
# define FLAG_CHAN_LL_STR	"l"
# define FLAG_CHAN_BL_STR	"b"
# define FLAG_CHAN_KL_STR	"k"

/*
** Can't be added
*/
typedef enum		e_flags_chan_user
  {
    FLAG_OL = 0b01,
    FLAG_VL = 0b10
  }			t_flags_chan_user;

# define FLAG_CHAN_OL_STR	"o"
# define FLAG_CHAN_VL_STR	"v"

typedef struct		s_chan_user
{
  struct s_duser	*info;
  t_flags_chan_user	mode;
  struct s_chan_user	*next;
}			t_chan_user;

/*
** Channels names are strings (beginning with a '&' or '#' character) of
** length up to 200 characters. Apart from the the requirement that the
** first character being either '&' or '#'; the only restriction on a
** channel name is that it may not contain any spaces (' '), a control G
** (^G or ASCII 7), or a comma (',' which is used as a list item separator
** by the protocol).
*/
typedef struct		s_chan
{
  t_flags_chan		mode;
  char			name[CHAN_NAME_LEN];
  char			topic[CHAN_TOPIC_LEN];
  uint32_t		l;
  char			key[CHAN_KEY_LEN];
  t_chan_user		*users;
}			t_chan;

typedef struct		s_chan_l
{
  t_chan		data;
  struct s_chan_l	*next;
}			t_chan_l;

typedef struct		s_irc
{
  t_bool		quit;
  struct s_duser_l	*users;
  t_chan_l		*chans;
}			t_irc;

t_chan_l	*new_chan(char *name);
t_state		add_chans_to_list(t_chan_l **list, t_chan_l *chan);
t_state		add_user_to_chan(t_chan *chan, struct s_duser *user);

#endif /* !CHAN_H_ */
