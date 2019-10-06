%{
#include <stdio.h>
%}

%token NUMBER PLUS MULT EOL
%%
goal : eval goal {}
	 | eval 	 {}
	 ;
eval : expr EOL { printf("=%d\n", $1); }
	 ;
expr : NUMBER { printf("number = %d\n", $1); $$ = $1; }
	 | expr PLUS expr { $$ = $1 + $3; }
	 | expr MULT expr { $$ = $1 * $3; }
	 ;
%%

int yyerror(char* s) {
	return printf("%s\n", s);
}
