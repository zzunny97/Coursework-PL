%{
#include <stdlib.h>
#include "cal.tab.h"
%}

int [0-9]+
number (([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+))
variable [a-zA-Z]+

%%
{number}	{  yylval.dval = atof(yytext); return NUMBER; }
{variable}	{  yylval.idx = find_idx(yytext); return ID; }
"\n"		;
[ \t]+		;
[;]			{ return SEMI; } 
[-+*/!]		{ return *yytext; }
.			;		
%%
