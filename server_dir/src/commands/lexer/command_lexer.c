/*
** command_lexer.c for  in ./
**
** Made by Jean Fauquenot
** Login   <fauque_j@epitech.net>
**
** Started on  Tue Apr 22 17:25:17 2014 Jean Fauquenot
** Last update Thu Apr 24 13:57:19 2014 Jean Fauquenot
*/

#include	"command.h"
#include	"error.h"
#include	"usual.h"
#include	"lexer.h"

/*
**   <message>  ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
**   <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
**   <command>  ::= <letter> { <letter> } | <number> <number> <number>
**   <SPACE>    ::= ' ' { ' ' }
**   <params>   ::= <SPACE> [ ':' <trailing> | <middle> <params> ]
**   <middle>   ::= <Any *non-empty* sequence of octets not including SPACE
**                   or NUL or CR or LF, the first of which may not be ':'>
**   <trailing> ::= <Any, possibly *empty*, sequence of octets not including
**                   NUL or CR or LF>
**   <crlf>     ::= CR LF
**
*************************************************************************
**
**   <target>     ::= <to> [ "," <target> ]
**   <to>         ::= <channel> | <user> '@' <servername> | <nick> | <mask>
**   <channel>    ::= ('#' | '&') <chstring>
**   <servername> ::= <host>
**   <host>       ::= see RFC 952 [DNS:4] for details on allowed hostnames
**   <nick>       ::= <letter> { <letter> | <number> | <special> }
**   <mask>       ::= ('#' | '$') <chstring>
**   <chstring>   ::= <any 8bit code except SPACE, BELL, NUL, CR, LF and
**                     comma (',')>
**
*************************************************************************
**
**   <user>       ::= <nonwhite> { <nonwhite> }
**   <letter>     ::= 'a' ... 'z' | 'A' ... 'Z'
**   <number>     ::= '0' ... '9'
**   <special>    ::= '-' | '[' | ']' | '\' | '`' | '^' | '{' | '}'
**   <nonwhite>   ::= <any 8bit code except SPACE (0x20), NUL (0x0), CR
**                   (0xd), and LF (0xa)>
*/
t_bool		command_lexer(char *scmd, t_cmd *cmd)
{
  if (l_message(&scmd, cmd) != TRUE)
    {
      return (FALSE);
    }
  return (TRUE);
}
