/*
** e_join_aux.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 17:36:02 2014 Jean Fauquenot
** Last update Sun Apr 27 22:25:46 2014 Jean Fauquenot
*/

#include	"execute.h"

#include	<string.h>

static t_bool	is_valid_chan(char *chan)
{
  if ((chan[0] != '#' && chan[0] != '&')
      || strlen(chan) > CHAN_NAME_LEN
      || chan[0] == '\0')
    return (FALSE);
  return (TRUE);
}

static t_bool	user_in_chan(char *param, t_duser *user)
{
  size_t	i;

  i = 0;
  while (i < MAX_CHANNEL_BY_USER)
    {
      if (user->channel[i] && strcmp(param, user->channel[i]->name) == 0)
	return (TRUE);
      i++;
    }
  return (FALSE);
}

t_state		invalid_join(char *param, t_duser *user)
{
  if (!is_valid_chan(param))
    {
      error_to_client(user, 403, "%s :No such channel", param);
      return (FAILURE_L1);
    }
  if (array_chan_len(user) >= MAX_CHANNEL_BY_USER)
    {
      error_to_client(user, 405,
		      "%s :You have joined too many channels", param);
      return  (FAILURE_L1);
    }
  if (user_in_chan(param, user))
    {
      return  (FAILURE_L1);
    }
  return (SUCCESS);
}
