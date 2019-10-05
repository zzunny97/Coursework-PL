%{
#include <stdlib.h>
#include "cal.tab.h"
%}

number [0-9]+|([0-9]*)|"."([0-9]+)
%%
{number} { yylval = atof(yytext); return NUMBER; }
"+"		 { return PLUS; }
"-"		 { return MINUS; }
"*"		 { return MULT; }
"/"		 { return DIV; }
"\n"	 { return EOL; }
" "			; 
.		 { yyerror("unexpected char"); }
%%
