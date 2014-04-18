/*
** usual.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Thu Apr 17 13:27:14 2014 Jean Fauquenot
** Last update Fri Apr 18 16:39:59 2014 Jean Fauquenot
*/

#ifndef USUAL_H_
# define USUAL_H_

# include		<stdlib.h>

# define LEN(x)			(sizeof(x) / sizeof(*x))

# ifdef UNUSED
# elif defined(__GNUC__)
#  define UNUSED(x)		UNUSED_ ## x __attribute__((unused))
# elif defined(__LCLINT__)
#  define UNUSED(x)		/*@unused@*/ x
# else
#  define UNUSED(x)		x
# endif

/*
** Return state of functions
**
**
*/
typedef enum		e_state
  {
    SUCCESS = 0,
    FAILURE_L1 = 1,
    FAILURE = 2
  }			t_state;

typedef enum		e_bool
  {
    FALSE,
    TRUE
  }			t_bool;

#endif /* !USUAL_H_ */
