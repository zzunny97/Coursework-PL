%{
#include <stdlib.h>
#include "cal.tab.h"
%}

int [0-9]+
tmp {int}|{int}(\.){int}
number (([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+))
variable [a-zA-Z]+

%%
{number}	{ printf("this is double %lf\n", atof(yytext)); yylval.dval = atof(yytext); return NUMBER; }
{variable}  { yylval.idx = find_idx(yytext); return VAR; }
"+" 	 	{ return ADD; }
"*"			{ return MULT; }
"-"			{ return ADD; }
"/"			{ return MULT; }
"="			{ return EQUAL; }
"\n"		{ return EOL; }
";"			{ return SEMI; }	
[ \t]+		;
.			{ yyerror("unexpected char"); }
%%



