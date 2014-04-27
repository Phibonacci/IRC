/*
** usual.h for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Sat Apr 19 19:55:26 2014 Jean Fauquenot
** Last update Sat Apr 26 16:40:10 2014 Jean Fauquenot
*/

#ifndef USUAL_H_
# define USUAL_H_

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

int		array_ptr_len(char **);

#endif /* !USUAL_H_ */
