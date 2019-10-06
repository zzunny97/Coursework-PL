%{
#include <stdlib.h>
#include "cal.tab.h"
%}
number [0-9]+
double {number}(\.){number}
variable [a-zA-Z]+
%%
{double}	{ printf("this is double\n"); yylval.dval = atof(yytext); return NUMBER; }
{variable}	{ printf("this is variable\n"); yylval.ival = yytext[0]; return VARIABLE; }
"+" 	 	{ return PLUS; }
"*"			{ return MULT; }
"-"			{ return MINUS; }
"/"			{ return DIV; }
"\n"		{ return EOL; }
" "			;
.			{ yyerror("unexpected char"); }
%%



