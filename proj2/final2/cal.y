%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
	typedef struct varr {
		double vall;
		char* name;
	}varr;
	varr reg[MAX];
	int cur_idx;
%}

%union { 
	double dval; 
	int idx;
}


%nonassoc UMINUS
%token <dval> NUMBER
%token <idx> VAR 
%token PLUS MULT EOL MINUS DIV ASS

%type <dval> expr;
%type <dval> factor;

%%
goal : eval goal {}
	   | eval 	 {}
		 ;
eval : expr EOL { printf("=%lf\n", $1); }
		 | ASS VAR expr EOL { reg[$2].vall = $3; } 
		 ;
expr : factor { $$ = $1; }
		 | PLUS expr expr { printf("hi1\n"); $$ = $2 + $3; }
		 | MULT expr expr {  $$ = $2 * $3; }
		 | MINUS expr expr { $$ = $2 - $3; }
		 | DIV expr expr { $$ = $2 / $3; }
		 | '(' expr ')' { $$ = $2; }
		 | '-' expr %prec UMINUS { $$ = -$2; }
		 | '+' expr %prec UMINUS { $$ = $2; }
		 ;
factor : NUMBER { printf("bye1\n"); $$ = $1; }
			 | VAR { printf("bye2\n"); $$ = reg[$1].vall; }
			 ;
%%

yyerror(char* s) {
			 //| '+' NUMBER %prec UMINUS { printf("bye3\n"); $$ = $2; }
			 //| '-' NUMBER %prec UMINUS { printf("bye4\n"); $$ = -$2; }
	return printf("%s\n", s);
}

int find_idx(char* var_name) {
	for(int i=0; i<cur_idx; i++) {
		if(strcmp(reg[i].name, var_name)==0) return i;		
	}
	reg[cur_idx].name = (char*)malloc(strlen(var_name));
	strcpy(reg[cur_idx].name, var_name);
	int ret = cur_idx;
	cur_idx++;
	return ret;
}
//| '-' expr %prec UMINUS { $$ = -$2; }
