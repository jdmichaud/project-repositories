#ifndef PARSE_PARSE_HH_
# define PARSE_PARSE_HH_

#include <string>

#define YY_DECL \
  int	yylex (union yystype *yylval)
YY_DECL;

void	scan_open (const std::string &name);
void	scan_close (void);

int	yyparse ();

void	*parse (const string& fname);

#endif /* !PARSE_PARSE_HH_ */
 
