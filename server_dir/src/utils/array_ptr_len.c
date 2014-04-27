/*
** array_ptr_len.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 26 16:40:30 2014 Jean Fauquenot
** Last update Sat Apr 26 16:41:37 2014 Jean Fauquenot
*/

#include	"usual.h"

#include	<unistd.h>

int		array_ptr_len(char **array)
{
  size_t	len;

  len = 0;
  while (array[len])
    {
      ++len;
    }
  return (len);
}
