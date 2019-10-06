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
%token ADD MULT EOL EQUAL SEMI

%type <dval> expr;
%type <dval> assgn;
%type <dval> term;
%type <dval> factor;
%%
list : list stmt SEMI {}
	 | stmt SEMI {}
	 ;

stmt : expr {}
     | assgn {};

assgn : EQUAL VAR stmt { reg[$2].vall = $3; };

expr : term { printf("=%lf\n", $1); }
	 | ADD expr term { 
	 	if($1=="+") $$ = $2 + $3;
		else if($1=="-") $$ = $2 - $3;
		else { printf("error\n"); }
	 }
term : factor {}
	 | MULT term factor {
	 	if($1=="*") $$ = $2 * $3;
		else if($1=="/") $$ = $2 / $3;
		else { printf("error\n"); }
	 };
factor : VAR {$$ = reg[$1].vall; }
	   | NUMBER { $$ = $1; }
	   | '-' factor { $$ = -$1; } 
	   | '(' expr ')' { $$ = $2; }



%%

yyerror(char* s) {
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
