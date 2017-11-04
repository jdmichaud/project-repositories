%option noyywrap stack
%s PARSE C COMMENT C_STRING TAIL STRING_IN_PARSE
%{
#include "my_printf.h"
#include "my_print_error.h"
#include "tree.h"
#include "utils.h"
#include "my_strdup.h"
#include "list.h"

int		gl_n_line;
int		gl_line_com;
int		gl_n_col;
int		gl_col_com;
char		*gl_str;
t_list		*gl_list;
%}
%%
<INITIAL>
{
  "%{" {
    gl_n_col = 1;
    gl_n_line = 1;
    BEGIN(C);
  }
  "%%" {
    gl_n_col = 0;
    BEGIN(PARSE);
  }
  .+ ;
  \n {
    gl_n_col = 0;
    ++gl_n_line;
  }
  <<EOF>> return (EOF);
}

<PARSE>
{
  [, \t]* gl_n_col += my_strlen(yytext);
  "%%" {
    BEGIN(TAIL); 
    return (-3);
  }
  "\n" {
    gl_n_col = 0;
    ++gl_n_line;
  }
  [A-Za-z._][A-Za-z_0-9.]* {
    gl_n_col += my_strlen(yytext);
    gl_str = my_strdup(yytext);
    return (0);
  }
  "\"" {
    gl_line_com = gl_n_line;
    gl_list = NULL;
    gl_str = NULL;
    BEGIN(STRING_IN_PARSE);
  }
  #[^\n.]* ;
  <<EOF>> return (2);
}

<C>
{
  "%}" {
    fflush(stdout);
    BEGIN(INITIAL);
  }
  "/*" {
    ECHO;
    gl_line_com = gl_n_line;
    gl_col_com = gl_n_col;
    yy_push_state(COMMENT);
  }
  "\n" {
    gl_n_col = 0;
    ECHO;
    ++gl_n_line;
  }
  "\"" {
    ECHO;
    gl_line_com = gl_n_line;
    gl_col_com = gl_n_col;
    yy_push_state(C_STRING);
  }
  . {
    ++gl_n_col;
    ECHO;
  }
  <<EOF>> return (5);
}

<TAIL>
{
  "/*" {
    ECHO;
    gl_line_com = gl_n_line;
    gl_col_com = gl_n_col;
    yy_push_state(COMMENT);
  }
  "\n" {
    gl_n_col = 0;
    ++gl_n_line;
    ECHO;
  }
  "\"" {
    ECHO;
    gl_line_com = gl_n_line;
    gl_col_com = gl_n_col;
    yy_push_state(C_STRING);
  }
  . {
    ++gl_n_col;
    ECHO;
  }
  <<EOF>> return (-2);
}

<COMMENT>
{
  "*/" {
    ECHO;
    yy_pop_state();
  }
  "\n" { 
    gl_n_col = 0;
    ++gl_n_line;
    ECHO;
  }
  <<EOF>> return (3);
}

<C_STRING>
{
  \\. {
    ECHO; 
    ++gl_n_col;
  }
  "\"" {
    ECHO;
    yy_pop_state();
  }
  "%}" return (4);
  "\n" { 
    gl_n_col = 0;
    ++gl_n_line;
    ECHO;
  }  
  . ECHO; ++gl_n_col;
  <<EOF>> return (4);
}

<STRING_IN_PARSE>
{
  "\"" {
    push(&gl_list, '\0');
    gl_str = collapse(gl_list);
    free_list(&gl_list);
    BEGIN(PARSE);
    return (0);
  }
  "\\a"  push(&gl_list, '\a');
  "\\b"  push(&gl_list, '\b');
  "\\e"  push(&gl_list, '\e');
  "\\n"  push(&gl_list, '\n');
  "\\f"  push(&gl_list, '\f');
  "\\r"  push(&gl_list, '\r');
  "\\t"  push(&gl_list, '\t');
  "\\v"  push(&gl_list, '\v');
  \\.    push(&gl_list, yytext[1]);
  \\x[0-9a-f]{1,3} {
    push(&gl_list, my_dtoc(strtol(&yytext[2], NULL, 16)));
  }
  \\[0-7]{1,3} {
    push(&gl_list, my_dtoc(strtol(&yytext[1], NULL, 8)));    
  }
  [^\\\n\"]* {
    int	i;
    
    for (i = 0; yytext[i]; ++i)
      push(&gl_list, yytext[i]);
  }
  "\n" {
    gl_n_col = 0;
    ++gl_n_line;
  }
  <<EOF>> return (4);
}
%%


