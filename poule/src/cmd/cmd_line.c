#include <stdio.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <readline/readline.h>
#include <readline/history.h>

#define PROMPT "Poule: "

value	copy_string (char *);

value	make_str (char *s)
{ 
  char *tmp;

  if (!s)
      return copy_string("\n");
  tmp = s;
  s = strcat(tmp, "\n");
  return copy_string(s);
}

value	main_c (void)
{
  char *line = readline (PROMPT);
  
  if (line)
    add_history (line);
  return make_str (line);
}
