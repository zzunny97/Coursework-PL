%{
#include <stdlib.h>
#include "cal.tab.h"
%}

int [0-9]+
tmp {int}|{int}(\.){int}
number (([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+))

variable [a-zA-Z]+

%%
{number}	{ printf("this is number %lf\n", atof(yytext)); yylval.dval = atof(yytext); return NUMBER; }
{variable}  { yylval.idx = find_idx(yytext); return VAR; }
"+" 	 	{ return PLUS; }
"*"			{ return MULT; }
"-"			{ return MINUS; }
"/"			{ return DIV; }
"="			{ return ASS; }
"\n"		{ return EOL; }
";"			;	
[ \t]+		;
.			{ yyerror("unexpected char"); }
%%



//number [-]((([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)))|((([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)))|[+]((([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)))

