/*
** main.c for main in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 13:58:25 2014 Gabriel Poulet de Grimouard
** Last update Sun Apr 27 23:26:25 2014 Gabriel Poulet de Grimouard
*/

#include <stdlib.h>

#include "user.h"
#include "client.h"

int		main()
{
  t_duser	*user;

  user = user_create();
  user_cmd(user);
  free(user);
  return (0);
}
