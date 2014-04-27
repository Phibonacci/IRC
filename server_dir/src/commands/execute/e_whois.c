/*
** e_whois.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sun Apr 27 11:45:02 2014 Jean Fauquenot
** Last update Sun Apr 27 19:25:26 2014 Jean Fauquenot
*/

#include	"execute.h"

t_state		e_whois(t_irc *UNUSED(irc), t_duser *user, t_cmd *cmd)
{
  if (user->identify == FALSE)
    return (SUCCESS);
  (void)user;
  (void)cmd;
  return (SUCCESS);
}
