%{
#include <stdlib.h>
#include "cal.tab.h"
%}

int [0-9]+
tmp {int}|{int}(\.){int}
number (([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+))

variable [a-zA-Z]+

%%
{number}	{  yylval.dval = atof(yytext); return NUMBER; }
{variable}  { yylval.idx = find_idx(yytext); return VAR; }
"\n"			 { return EOL; }
"="				 { return ASS; }
[ \t]+		 ;
[;]				 { return SEMI; } 
[-+*/!]		 { return *yytext; }
.					{ yyerror("unexpected char"); }
%%



//number [-]((([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)))|((([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)))|[+]((([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+)))

//"+" 	 	{ return PLUS; }
//"*"			{ return MULT; }
//"-"			{ return MINUS; }
//"/"			{ return DIV; }
//"="			{ return ASS; }
//.			{ yyerror("unexpected char"); printf("error string: %s\n", yytext); }
