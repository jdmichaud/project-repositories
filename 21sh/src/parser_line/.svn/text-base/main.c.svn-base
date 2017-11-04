/*
** main.c for  in 
** 
** Made by Actarus Acta
** Login   <Actarus@epita.fr>
** 
** Started on  Tue Dec 11 20:08:24 2001 Actarus Acta
** Last update Thu Dec 13 12:47:44 2001 jonathan mimouni
*/

#include <stdio.h>
#include <stdlib.h>
#include "list_cmd.h"
#include "parser_line.h"
#include "errors.h"

int	main()
{
  char *inst[] = 
  {
    "echo test",
    "echo test echo test2 echo test3 echo test4",
    "",
    "ls -la; echo $?;ls",
    ";",
    "emacs cool &",
    "emacs cool &; emacs cool2",
    "emacs cool &| emacs cool2",
    "emacs test && emacs cool3" ,
    "emacs test &&; emacs cool3" ,
    "ls -la &&ls && rm -fr ~/* && echo a pu de compte ...",
    "ls -la ||ls && rm -fr ~/* || echo a pu de compte ...",
    "||ls && rm -fr ~/* || echo a pu de compte ...",
    "\\",
    "\\slach \\ ca_slach\\un max",
    "'hello'",
    "echo 'emacs cool & ; echo cool&&&'",
    "echo \"emacs cool & ; echo cool&&&\"",
    "echo 'emacs cool\\' & ; echo cool&&&'",
    "echo 'emacs cool\\' & ; echo cool&&&' && echo \"et un backslash\\\"",
    "pwd || cp 21sh /home/usr/shell/; kill -9 zsh && echo FinTest"
  };
  int		i;
  t_list_cmd	*list;

  for (i = 0; i < 22; ++i)
    {
      printf("cmd ---> %s\n", inst[i]);
      list = parser_line(inst[i]);
      if (list == NULL)
	{
	  if (*(inst[i]) == '\0')
	    printf("Ne m'arnaque pas petit, la ligne etait vide\n");
	}
      else
	list_cmd_print(list);
      list_cmd_free(&list);
      printf("\n");
    }
  return (0);
}
