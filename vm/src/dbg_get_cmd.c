/*
** dbg_get_cmd.c for  in 
** 
** Made by GIZMO
** Login   <grimau_r@epita.fr>
** 
** Started on  Wed Jan  9 20:53:17 2002 GIZMO
** Last update Fri Jan 11 16:15:01 2002 romain bottier
*/

#include <unistd.h>
#include "my.h"
#include "my_struct.h"
#include "process.h"
#include "dbg.h"
#include "dbg_cmd.h"
#include "dbg_parse.h"
#include "my_printf.h"
#include "my_print_error.h"

void	show_prompt(void)
{
  my_printf("(cdb) ");
}

char    *readcmd(void)
{
  char  c;
  int   i;
  int   len;
  char  buf[MAX_SIZE_CMD];
  char  *cmd;
  
  buf[0] = '\0';
  for (i = 0, read(1, &c, 1); i < MAX_SIZE_CMD && c != '\n'; i++)
    {
      buf[i] = c;
      read(1, &c, 1);
    }
  buf[i] = '\0';
  if (i < MAX_SIZE_CMD)
    {
      len = my_strlen(buf);
      cmd = my_xmalloc((len + 1) * sizeof (char));
      my_strcpy(cmd, buf);
      return (cmd);
    }
  my_print_error("Command too long\n");
  return (0);
}

void	wait_for_cmd(t_vm *v, t_player *p)
{
  char	*cmd;
  
  while (v->in_debug == CDB_ON)
    {
      show_prompt();
      if ((cmd = readcmd()) != 0)
	cmd_parseline(v, cmd);
    }
}
