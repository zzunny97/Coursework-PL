%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 100
	typedef struct varr {
		double vall;
		char* name;
	}varr;
	varr reg[MAX];
	int cur_idx;
	int tmp;
%}

%union { 
	double dval; 
	int idx;
}


%token <dval> NUMBER
%token <idx> VAR 
%left '+' '-'
%left '*' '/'
%right ';'
%nonassoc UMINUS
%token EOL ASS SEMI
%type <dval> expr;
%type <dval> factor;


%%
goal : eval goal {} 
		 | eval {} 
		 ;
eval : expr  SEMI EOL { if($1 == INT_MIN) { printf("Unknown variable: %s\n", reg[tmp].name); } else printf("=%lf\n", $1); }
		 | ASS VAR expr SEMI EOL { reg[$2].vall = $3; } 
		 ;
expr : '+' expr expr { $$ = $2 + $3; }
		 | '*' expr expr { $$ = $2 * $3; }
		 | '-' expr expr { $$ = $2 - $3; }
		 | '/' expr expr { $$ = $2 / $3; }
		 | '(' expr ')' { $$ = $2; }
		 | factor { $$ = $1; }
		 ;
factor: NUMBER { $$ = $1; }
			| VAR { tmp = $1; $$ = reg[$1].vall; } 
		  | '!' NUMBER %prec UMINUS { $$ = -$2; }
		  | '!' VAR %prec UMINUS { $$ = -$2; }

%%

yyerror(char* s) {
//eval : expr EOL { if($1 == INT_MIN) { printf("Unknown variable: %s\n", reg[tmp].name); } else printf("=%lf\n", $1); }
//		 | ASS VAR expr EOL { reg[$2].vall = $3; } 
	return printf("%s\n", s);
}

int find_idx(char* var_name) {
	for(int i=0; i<cur_idx; i++) {
		if(strcmp(reg[i].name, var_name)==0) return i;		
	}
	reg[cur_idx].name = (char*)malloc(strlen(var_name));
	reg[cur_idx].vall = INT_MIN;
	strcpy(reg[cur_idx].name, var_name);
	int ret = cur_idx;
	cur_idx++;
	return ret;
}


