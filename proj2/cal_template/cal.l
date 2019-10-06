%{
#include <stdlib.h>
#include "cal.tab.h"
%}

number [0-9]+
%%
{number} 	{ yylval = atoi(yytext); return NUMBER; }
"+" 	 	{ return PLUS; }
"*"			{ return MULT; }
"\n"		{ return EOL; }
.			{ yyerror("unexpected char"); }
%%
