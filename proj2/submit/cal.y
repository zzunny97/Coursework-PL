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


%token <dval> NUMBER
%token <idx> VAR 
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%nonassoc UPLUS
%token EOL ASS
%type <dval> expr;


%%
goal : eval goal {}
	   | eval 	 {}
		 ;
eval : expr EOL { printf("=%lf\n", $1); }
		 | ASS VAR expr EOL { reg[$2].vall = $3; } 
		 ;
expr : '+' expr expr { printf("plus expr expr\n"); $$ = $2 + $3; }
		 | '*' expr expr { printf("mult expr expr\n"); $$ = $2 * $3; }
		 | '-' expr expr { printf("minus expr expr\n"); $$ = $2 - $3; }
		 | '/' expr expr { $$ = $2 / $3; }
		 | '(' expr ')' { $$ = $2; }
		 | '+' NUMBER %prec UPLUS { $$ = $2; }
		 | '-' NUMBER %prec UMINUS { $$ = -$2; }
		 | '+' VAR %prec UPLUS { $$ = $2; }
		 | '-' VAR %prec UMINUS { $$ = -$2; }
		 | VAR { $$ = reg[$1].vall; }
		 | NUMBER { $$ = $1; }
		 ;
%%

yyerror(char* s) {
//%token PLUS MULT EOL MINUS DIV ASS
//%type <dval> factor;
//%type <dval> factorr;
	/*
factor : factorr { printf("factor: %s\n", $1); $$ = $1; }

			 ;
factorr : VAR { printf("final: variable %s\n", reg[$1].vall); $$ = reg[$1].vall; }
			  | NUMBER { printf("final: number %lf\n", $1); $$ = $1; }
			  ;*/
			 //| MINUS factorr %prec UMINUS { printf("uminus %lf\n", $2); $$ = -$2; } 
			 //| PLUS factorr %prec UMINUS { printf("uplus %lf\n", $2); $$ = $2; } 
			 //| '+' factorr %prec UMINUS { printf("bye3\n"); $$ = $2; }
			 //| '-' factorr %prec UMINUS { printf("bye4\n"); $$ = -$2; }
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
