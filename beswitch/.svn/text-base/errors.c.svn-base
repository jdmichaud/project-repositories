/*
** errors.c for beswitch in 
** 
** Made by jean-daniel michaud
** Login   <michau_j@epita.fr>
** 
** Started on  Mon Nov 12 12:19:07 2001 jean-daniel michaud
** Last update Mon Nov 12 13:27:35 2001 jean-daniel michaud
*/


#include "errors.h"
#include "my_printf.h"
#include "my_print_error.h"

extern char	*gl_str;
extern int	gl_n_line;
extern int	gl_line_com;
extern int	gl_n_col;
extern int	gl_col_com;

t_func		tab[] =
{
  {0},
  {dupentry},
  {missend},
  {untcomment},
  {untstring},
  {missendc}
};

void	dupentry(char *f)
{
  my_print_error("duplicate entry:l.%d: %s\n", gl_n_line, gl_str);
  exit(1);
}

void	missend(char *f)
{
    my_print_error("missing: %%\n");
    exit(2);
}

void	untcomment(char *f)
{
  if (f)
    my_print_error("%s:%d.%d: unterminated comment\n", 
		   f, gl_col_com, gl_line_com);
  else
    my_print_error("stdin:%d.%d: unterminated comment\n", 
		   gl_col_com, gl_line_com);
  exit(3);
}
 
void	untstring(char *f)
{
  if (f)
    my_print_error("%s:%d.%d: unterminated string\n", 
		   f, gl_col_com, gl_line_com);
  else
    my_print_error("stdin:%d.%d: unterminated string\n", 
		   gl_col_com, gl_line_com);
  exit(4);
}
		  
void	missendc(char *f)
{
  my_print_error("missing: %}\n");
  exit(5);
}
