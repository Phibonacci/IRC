/*
** main.c for main in /home/drdrak/rendu/unix/PSU_2013_myirc/client_dir
**
** Made by Gabriel Poulet de Grimouard
** Login   <poulet_g@epitech.net>
**
** Started on  Fri Apr 18 13:58:25 2014 Gabriel Poulet de Grimouard
** Last update Mon Apr 21 18:40:03 2014 Gabriel Poulet de Grimouard
*/

#include "user.h"
#include "client.h"

int		main()
{
  t_muser	*user;

  user = user_create();
  user_cmd(user);
  free(user);
  return (0);
}
