%{
#define YYSTYPE double
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
%}

%union { int ival; double dval; }

%token <dval> NUMBER 
%token <ival> VARIABLE
%token PLUS MULT EOL MINUS DIV



%%
goal : eval goal {}
	 | eval 	 {}
	 ;
eval : expr EOL { printf("=%lf\n", $1); }
	 ;
expr : NUMBER { printf("number = %lf\n", $1);  $$ = $1; }
	 | PLUS expr expr { printf("number = %lf %lf\n", $2, $3); $$ = $2 + $3; }
	 | MULT expr expr { printf("number = %lf %lf\n", $2, $3); $$ = $2 * $3; }
	 | MINUS expr expr { printf("number = %lf %lf\n", $2, $3); $$ = $2 - $3; }
	 | DIV expr expr { printf("number = %d %d\n", $2, $3); $$ = $2 / $3; }
	 ;
%%

yyerror(char* s) {
	return printf("%s\n", s);
}


