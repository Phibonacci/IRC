/*
** error.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 16:14:24 2014 Jean Fauquenot
** Last update Fri Apr 18 20:15:02 2014 Gabriel Poulet de Grimouard
*/

#include	"error.h"
#include	"bin_name.h"

#include	<stdarg.h>
#include	<stdio.h>

t_state		merror(char *format, ...)
{
  va_list	ap;

  fprintf(stderr, "%s", EHEADER);
  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);
  fprintf(stderr, "\n");
  return (FAILURE);
}
