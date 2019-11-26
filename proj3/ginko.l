%{
#include <stdio.h>
#include <stdlib.h>
#include "ginko.tab.h"
%}

number (([0-9]+(\.[0-9]*)?)|([0-9]*\.[0-9]+))
variable [a-zA-Z]+

%%
"SET"		{ printf("LEX SET\n"); return SET; }
"to"		{ return to; }
"IF"		{ return IF;}
"THEN"		{ return THEN; }
"ENDIF"		{ return ENDIF; }
"ELSE"		{ return ELSE;}
"FUNC"		{ return FUNC;}
"RETURN"	{ return RETURN; }
"ENDWHILE"	{ return ENDWHILE; } 
"PRINT"		{ return PRINT; }
"WHILE"		{ return WHILE; }
"DO"		{ return DO; }



{number}	{  printf("%lf\n", atof(yytext)); yylval.dval = atof(yytext); return NUMBER; }
{variable}	{  printf("%s\n", yytext); yylval.idx = *yytext- 'a'; return ID; }
[ \t\n]+	;
[-+*/!]		{ return *yytext; }
[;]			{ return *yytext; } 	
.			;		
%%
