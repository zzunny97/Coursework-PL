%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUMBER PLUS MINUS MULT DIV EOL
%%
goal: eval goal {}
	 | eval 	{}
	 ;
eval: expr EOL {printf("=%f\n", $1);}
	 ;

expr: NUMBER { $$ = $1; }
	 | PLUS expr expr { $$ = $2 + $3; }
	 | MINUS expr expr { $$ = $2 - $3; }
	 | MULT expr expr { $$ = $2 * $3; }
	 | DIV expr expr { $$ = $2 / $3; }
	 ;
%%

int yyerror(char* s){
	return printf("%s\n", s);
}
