/*
** main.c for main in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 13:58:25 2014 Gabriel Poulet de Grimouard
** Last update Fri Apr 18 15:18:32 2014 Gabriel Poulet de Grimouard
*/

#include "user.h"
#include "client.h"

int		main()
{
  t_user	*user;

  user = user_create();
  user_cmd(user);
  free(user);
  return (0);
}
